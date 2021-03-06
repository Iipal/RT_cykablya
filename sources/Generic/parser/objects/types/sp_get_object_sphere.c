/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:01:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 13:16:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern inline bool __attribute__((INLINE,ARCH))
	s_validate_sphere_data(const JSON_Object *restrict obj_json,
		const size_t obj_serial)
{
	IFDO_F(4 != json_object_get_count(obj_json),
		ERRIN_D(P_OBJECTS, obj_serial + 1, E_INVALID_COUNT, E_DEF_PARAM(4)));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_POSITION, JSONArray),
		ERRIN_N(P_OT_SPHERE, obj_serial + 1, P_O_POSITION, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_RADIUS, JSONNumber),
		ERRIN_N(P_OT_SPHERE, obj_serial + 1, P_O_RADIUS, E_TYPE_FMT));
	return (true);
}

extern inline t_sphere_sf __attribute__((INLINE,ARCH))
	*s_get_sphere_data(const JSON_Object *restrict obj_json,
		const size_t obj_serial)
{
	t_sphere_sf	*s;
	t_v3sf		pos;
	float		radius;

	NO_F(spu_get_v3sf_arr(&pos, json_object_get_array(obj_json, P_O_POSITION),
		P_O_POSITION, obj_serial));
	radius = json_object_get_number(obj_json, P_O_RADIUS);
	MEM(t_sphere_sf, s, 1UL, E_ALLOC);
	*s = sphere(pos, radius);
	return (s);
}

bool __attribute__((ALIGN,ARCH))
	sp_get_object_sphere(const JSON_Object *obj_json,
		union u_hitables *restrict obj,
		const size_t obj_serial)
{
	t_material_sf	*mat;
	t_sphere_sf		*s;

	NO_F(s_validate_sphere_data(obj_json, obj_serial));
	NO_F(mat = sp_get_object_material(obj_json, obj_serial));
	NO_F(s = s_get_sphere_data(obj_json, obj_serial));
	*obj = (union u_hitables){{ SPHERE, 0, s, mat }};
	return (true);
}
