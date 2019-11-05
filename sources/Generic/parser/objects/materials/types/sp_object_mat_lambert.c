/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_lambert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:01:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 21:11:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline bool	s_validate_lambert_data(JSON_Object const *mat,
						size_t const obj_serial)
{
	NODO_F(json_object_has_value_of_type(mat, P_O_M_ALBEDO, JSONArray),
		ERRIN_N(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_ALBEDO, E_INVALID));
	return (true);
}

t_material_sf	*sp_object_mat_lambert(JSON_Object const *mat,
			union u_hitables *restrict obj,
			size_t const obj_serial)
{
	t_material_sf	*m;
	t_v3sf			albedo;

	NO_R(s_validate_lambert_data(mat, obj_serial), NULL);
	NO_F(sp_get_v3sf_arr(&albedo, json_object_get_array(mat, P_O_M_ALBEDO),
		P_O_M_ALBEDO, obj_serial));
	MEM(t_material_sf, m, 1UL, E_ALLOC);
	*m = material(LAMBERTIAN, albedo);
	return (m);
}
