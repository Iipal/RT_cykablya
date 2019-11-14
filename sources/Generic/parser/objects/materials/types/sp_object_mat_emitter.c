/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_emitter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:20:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 19:34:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf __attribute__((ALIGN,ARCH))
	*sp_object_mat_emitter(JSON_Object const *restrict mat,
		const size_t obj_serial)
{
	t_material_sf	*m;
	t_v3sf			albedo;

	NODO_R(json_object_has_value_of_type(mat, P_O_M_ALBEDO, JSONArray),
		ERRIN_N(P_OBJECTS " "  P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_ALBEDO, E_INVALID), NULL);
	NO_F(spu_get_v3sf_arr(&albedo, json_object_get_array(mat, P_O_M_ALBEDO),
		P_O_M_ALBEDO, obj_serial));
	MEM(t_material_sf, m, 1UL, E_ALLOC);
	*m = material(COLOR, albedo);
	return (m);
}
