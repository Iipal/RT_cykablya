/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_metal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:21:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 18:01:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf __attribute__((ALIGN,ARCH))
	*sp_object_mat_metal(JSON_Object const *restrict mat,
		const size_t obj_serial)
{
	t_material_sf	*m;
	t_v3sf			albedo;
	float			fuzz;

	IFDO_R(3 != json_object_get_count(mat),
		ERRIN_D(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			E_INVALID_COUNT, E_DEF_PARAM(3)), NULL);
	NODO_R(json_object_has_value_of_type(mat, P_O_M_ALBEDO, JSONArray),
		ERRIN_N(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_ALBEDO, E_INVALID), NULL);
	NODO_R(json_object_has_value_of_type(mat, P_O_M_FUZZ, JSONNumber),
		ERRIN_N(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_FUZZ, E_INVALID), NULL);
	NO_F(spu_get_v3sf_arr(&albedo, json_object_get_array(mat, P_O_M_ALBEDO),
		P_O_M_ALBEDO, obj_serial));
	fuzz = json_object_get_number(mat, P_O_M_FUZZ);
	MEM(t_material_sf, m, 1UL, E_ALLOC);
	*m = material(METAL, albedo, fuzz);
	return (m);
}
