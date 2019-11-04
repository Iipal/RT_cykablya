/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:01:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/04 12:32:07 by tmaluh           ###   ########.fr       */
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
	NO_F(sp_get_object_material(obj_json, obj, obj_serial));
	NO_F(s_validate_sphere_data(obj_json, obj_serial));
	return (true);
}
