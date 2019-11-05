/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:01:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 20:50:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline bool	s_validate_normal_data(JSON_Object const *mat,
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

t_material_sf		*sp_object_mat_normal(JSON_Object const *mat,
						union u_hitables *restrict obj,
						size_t const obj_serial)
{
	t_material_sf	*m;
	t_v3sf			albedo;
	float			fuzz;

	NO_R(s_validate_normal_data(mat, obj_serial), NULL);
	MEM(t_material_sf, m, 1UL, E_ALLOC);
	NO_F(sp_get_v3sf_arr(&albedo, json_object_get_array(mat, P_O_M_ALBEDO),
		P_O_M_ALBEDO, obj_serial));
	fuzz = json_object_get_number(mat, P_O_M_FUZZ);
	*m = material(METAL, albedo, fuzz);
	return (m);
}
