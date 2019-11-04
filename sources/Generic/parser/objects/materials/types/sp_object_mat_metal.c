/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_metal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:21:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/04 12:27:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_object_mat_metal(JSON_Object const *mat,
			union u_hitables *obj,
			size_t const obj_serial)
{
	NODO_F(json_object_has_value_of_type(mat, P_O_M_ALBEDO, JSONArray),
		ERRIN_N(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_ALBEDO, E_INVALID));
	NODO_F(json_object_has_value_of_type(mat, P_O_M_FUZZ, JSONNumber),
		ERRIN_N(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_FUZZ, E_INVALID));
	return (true);
}
