/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:19:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 13:17:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern inline bool __attribute__((INLINE,ARCH))
	s_validate_cylinder_data(const JSON_Object *restrict obj_json,
		const size_t obj_serial)
{
	bool	is_top;
	bool	is_height;

	IFDO_F(5 != json_object_get_count(obj_json),
		ERRIN_D(P_OBJECTS, obj_serial + 1, E_INVALID_COUNT, E_DEF_PARAM(5)));
	is_top = json_object_has_value_of_type(obj_json, P_O_TOP, JSONArray);
	is_height = json_object_has_value_of_type(obj_json, P_O_HEIGHT, JSONNumber);
	IFDO_F(!is_height && !is_top,
		ERRIN_D(P_OBJECTS, obj_serial + 1, E_CYLINDER_FMT, E_I_CYLINDER));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_POSITION, JSONArray),
		ERRIN_N(P_OT_CYLINDER, obj_serial + 1, P_O_POSITION, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_RADIUS, JSONNumber),
		ERRIN_N(P_OT_CYLINDER, obj_serial + 1, P_O_RADIUS, E_TYPE_FMT));
	return (true);
}

extern inline t_cylinder_sf __attribute__((ALIGN,ARCH))
	*s_get_cylinder_data(const JSON_Object *restrict obj_json,
		const size_t obj_serial)
{
	t_cylinder_sf	*c;
	t_v3sf			h_t;
	t_v3sf			pos;
	float			radius;
	const bool		is_height = json_object_has_value(obj_json, P_O_HEIGHT);

	NO_F(spu_get_v3sf_arr(&pos, json_object_get_array(obj_json, P_O_POSITION),
		P_O_POSITION, obj_serial));
	radius = json_object_get_number(obj_json, P_O_RADIUS);
	MEM(t_cylinder_sf, c, 1UL, E_ALLOC);
	if (is_height)
	{
		h_t[0] = spu_value_inrange(json_object_get_number(obj_json, P_O_HEIGHT),
					P_O_HEIGHT_MIN, P_O_HEIGHT_MAX);
		*c = cylinder(pos, radius, h_t[0]);
	}
	else
	{
		NO_F(spu_get_v3sf_arr(&h_t, json_object_get_array(obj_json, P_O_TOP),
			P_O_TOP, obj_serial));
		*c = cylinder(pos, h_t, radius);
	}
	return (c);
}

bool __attribute__((ALIGN,ARCH))
	sp_get_object_cylinder(const JSON_Object *restrict obj_json,
						union u_hitables *restrict obj,
						const size_t obj_serial)
{
	t_material_sf	*mat;
	t_cylinder_sf	*c;

	NO_F(s_validate_cylinder_data(obj_json, obj_serial));
	NO_F(c = s_get_cylinder_data(obj_json, obj_serial));
	NO_F(mat = sp_get_object_material(obj_json, obj_serial));
	*obj = (union u_hitables){{ CYLINDER, 0, c, mat }};
	return (true);
}
