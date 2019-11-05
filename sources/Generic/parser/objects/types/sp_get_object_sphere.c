/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:01:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 15:44:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	s_validate_sphere_data(JSON_Object const *obj_json,
				size_t const obj_serial)
{
	NODO_F(json_object_has_value_of_type(obj_json, P_O_POSITION, JSONArray),
		ERRIN_N(P_OT_SPHERE, obj_serial + 1, P_O_POSITION, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_RADIUS, JSONNumber),
		ERRIN_N(P_OT_SPHERE, obj_serial + 1, P_O_RADIUS, E_TYPE_FMT));
	return (true);
}

bool		sp_get_object_sphere(JSON_Object const *obj_json,
				union u_hitables *obj,
				size_t const obj_serial)
{
	t_material_sf	*mat;
	t_sphere_sf		*s;
	t_v3sf			pos;
	float			radius;

	NO_F(mat = sp_get_object_material(obj_json, obj, obj_serial));
	MEM(t_sphere_sf, s, 1UL, E_ALLOC);
	NO_F(s_validate_sphere_data(obj_json, obj_serial));
	NO_F(sp_get_v3sf_arr(&pos, json_object_get_array(obj_json, P_O_POSITION),
		P_O_POSITION, obj_serial));
	radius = json_object_get_number(obj_json, P_O_RADIUS);
	*s = sphere(pos, radius);
	*obj = (union u_hitables){ SPHERE, 0, s, mat };
	return (true);
}