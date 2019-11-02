/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_metal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:21:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/02 18:46:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_object_mat_metal(JSON_Object const *mat,
			t_object *const obj,
			size_t const obj_serial)
{
	NODO_F(json_object_has_value_of_type(mat, P_O_M_ALBEDO, JSONArray),
		ERRIN_N(P_OBJECTS, obj_serial + 1,
			P_O_M_ALBEDO " " P_O_M_FUZZ, E_INVALID));
	NODO_F(json_object_has_value_of_type(mat, P_O_M_FUZZ, JSONNumber),
		ERRIN_N(P_OBJECTS, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_FUZZ, E_INVALID));
	obj->material = NULL;
	return (true);
}
