/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_cone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:15:51 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 22:11:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern inline bool __attribute__((INLINE,ARCH))
	s_validate_cone_data(const JSON_Object *obj_json,
		const size_t obj_serial)
{
	IFDO_F(5 != json_object_get_count(obj_json),
		ERRIN_D(P_OBJECTS, obj_serial + 1, E_INVALID_COUNT, E_DEF_PARAM(5)));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_POSITION, JSONArray),
		ERRIN_N(P_OT_CONE, obj_serial + 1, P_O_POSITION, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_RADIUS, JSONNumber),
		ERRIN_N(P_OT_CONE, obj_serial + 1, P_O_RADIUS, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_HEIGHT, JSONNumber),
		ERRIN_N(P_OT_CONE, obj_serial + 1, P_O_HEIGHT, E_TYPE_FMT));
	return (true);
}

extern inline t_cone_sf __attribute__((INLINE,ARCH))
	*s_get_cone_data(const JSON_Object *obj_json,
		const size_t obj_serial)
{
	t_cone_sf	*c;
	t_v3sf		pos;
	float		radius;
	float		height;

	NO_F(spu_get_v3sf_arr(&pos, json_object_get_array(obj_json, P_O_POSITION),
		P_O_POSITION, obj_serial));
	radius = json_object_get_number(obj_json, P_O_RADIUS);
	height = spu_value_inrange(json_object_get_number(obj_json, P_O_HEIGHT),
		P_O_HEIGHT_MIN, P_O_HEIGHT_MAX);
	MEM(t_cone_sf, c, 1UL, E_ALLOC);
	*c = cone(pos, radius, height);
	return (c);
}

bool __attribute__((ALIGN,ARCH))
	sp_get_object_cone(const JSON_Object *obj_json,
		union u_hitables *restrict obj,
		const size_t obj_serial)
{
	t_material_sf	*mat;
	t_cone_sf		*c;

	NO_F(s_validate_cone_data(obj_json, obj_serial));
	NO_F(mat = sp_get_object_material(obj_json, obj, obj_serial));
	NO_F(c = s_get_cone_data(obj_json, obj_serial));
	*obj = (union u_hitables){{ CONE, 0, c, mat }};
	return (true);
}
