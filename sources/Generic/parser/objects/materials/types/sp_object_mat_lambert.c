/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_lambert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:01:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 16:55:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf __attribute__((ALIGN,ARCH))
	*sp_object_mat_lambert(JSON_Object const *restrict mat,
		union u_hitables *restrict obj,
		const size_t obj_serial)
{
	t_material_sf	*m;
	t_v3sf			albedo;

	IFDO_R(2 != json_object_get_count(mat),
		ERRIN_D(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			E_INVALID_COUNT, E_DEF_PARAM(2)), NULL);
	NODO_R(json_object_has_value_of_type(mat, P_O_M_ALBEDO, JSONArray),
		ERRIN_N(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_ALBEDO, E_INVALID), NULL);
	NO_R(spu_get_v3sf_arr(&albedo, json_object_get_array(mat, P_O_M_ALBEDO),
		P_O_M_ALBEDO, obj_serial), NULL);
	MEM(t_material_sf, m, 1UL, E_ALLOC);
	*m = material(LAMBERTIAN, albedo);
	return (m);
}
