/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_triangle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:19:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 10:10:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern inline bool __attribute__((ALIGN,ARCH))
	s_validate_triangle_data(const JSON_Object *restrict obj_json,
		const size_t obj_serial)
{
	IFDO_F(3 != json_object_get_count(obj_json),
		ERRIN_D(P_OBJECTS, obj_serial + 1, E_INVALID_COUNT, E_DEF_PARAM(3)));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_POSITION, JSONArray),
		ERRIN_N(P_OT_TRIANGLE, obj_serial + 1, P_O_POSITION, E_TYPE_FMT));
	return (true);
}

extern inline t_tetrahedron_sf __attribute__((ALIGN,ARCH))
	*s_get_triangle_data(const JSON_Array *restrict obj_arr,
		const size_t obj_serial)
{
	t_tetrahedron_sf	*t;
	t_v3sf				temp[3];
	int8_t				i;

	i = -1;
	while (3 > ++i)
		NO_F(sp_get_v3sf_arr(&temp[i], json_array_get_array(obj_arr, i),
			P_O_POSITION, obj_serial));
	MEM(t_tetrahedron_sf, t, 1UL, E_ALLOC);
	*t = tetrahedron(temp[0], temp[1], temp[2]);
	return (t);
}

bool __attribute__((ALIGN,ARCH))
sp_get_object_triangle(const JSON_Object *restrict obj_json,
	union u_hitables *restrict obj,
	const size_t obj_serial)
{
	t_material_sf		*mat;
	t_tetrahedron_sf	*t;

	NO_F(s_validate_triangle_data(obj_json, obj_serial));
	NO_F(t = s_get_triangle_data(json_object_get_array(obj_json, P_O_POSITION),
		obj_serial));
	NO_F(mat = sp_get_object_material(obj_json, obj, obj_serial));
	*obj = (union u_hitables){ TETRAHEDRON, 0, t, mat };
	return (true);
}
