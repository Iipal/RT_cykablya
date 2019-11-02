/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:01:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/02 18:47:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_get_object_sphere(JSON_Object const *obj_json,
			t_object *const obj,
			size_t const obj_serial)
{
	JSON_Object const	*mat = json_object_get_object(obj_json, P_O_MATERIAL);
	char const			*mat_name = NULL;

	NODO_F(mat, ERRIN_N(P_O_SPHERE, obj_serial + 1, P_O_MATERIAL, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(mat, P_O_M_TYPE, JSONString),
		ERRIN_N(P_O_SPHERE, obj_serial + 1,
			P_O_MATERIAL " " P_O_TYPE, E_INVALID));
	mat_name = json_object_get_string(mat, P_O_TYPE);
	NO_F(sp_get_object_material(mat, mat_name, obj, obj_serial));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_POSITION, JSONArray),
		ERRIN_N(P_O_SPHERE, obj_serial + 1, P_O_POSITION, E_TYPE_FMT));
	return (true);
}
