/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_dielect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:02:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 21:10:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf	*sp_object_mat_dielect(JSON_Object const *mat,
			union u_hitables *restrict obj,
			size_t const obj_serial)
{
	t_material_sf	*m;

	NODO_R(json_object_has_value_of_type(mat, P_O_M_FUZZ, JSONNumber),
		ERRIN_N(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_FUZZ, E_INVALID), NULL);
	MEM(t_material_sf, m, 1UL, E_ALLOC);
	*m = material(DIELECTRIC, json_object_get_number(mat, P_O_M_FUZZ));
	return (m);
}
