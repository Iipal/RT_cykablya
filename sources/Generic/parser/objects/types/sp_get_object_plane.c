/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:15:51 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 13:17:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern inline bool __attribute__((INLINE,ARCH))
	s_validate_plane_data(const JSON_Object *restrict obj_json,
		const size_t obj_serial)
{
	IFDO_F(3 != json_object_get_count(obj_json),
		ERRIN_D(P_OBJECTS, obj_serial + 1, E_INVALID_COUNT, E_DEF_PARAM(3)));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_POSITION, JSONArray),
		ERRIN_N(P_OT_PLANE, obj_serial + 1, P_O_POSITION, E_TYPE_FMT));
	return (true);
}

extern inline t_plane_sf __attribute__((ALIGN,ARCH))
	*s_get_plane_data(const JSON_Array *restrict obj_arr,
		const size_t obj_serial)
{
	t_plane_sf		*p;
	t_v3sf			temp[4];
	int8_t			i;

	i = -1;
	while (4 > ++i)
		NO_F(spu_get_v3sf_arr(&temp[i], json_array_get_array(obj_arr, i),
			P_O_POSITION, obj_serial));
	MEM(t_plane_sf, p, 1UL, E_ALLOC);
	*p = plane(temp[0], temp[1], temp[2], temp[3]);
	return (p);
}

bool __attribute__((ALIGN,ARCH))
	sp_get_object_plane(const JSON_Object *restrict obj_json,
		union u_hitables *restrict obj,
		const size_t obj_serial)
{
	t_material_sf	*mat;
	t_plane_sf		*p;

	NO_F(s_validate_plane_data(obj_json, obj_serial));
	NO_F(p = s_get_plane_data(json_object_get_array(obj_json, P_O_POSITION),
		obj_serial));
	NO_F(mat = sp_get_object_material(obj_json, obj_serial));
	*obj = (union u_hitables){{ PLANE, 0, p, mat }};
	return (true);
}
