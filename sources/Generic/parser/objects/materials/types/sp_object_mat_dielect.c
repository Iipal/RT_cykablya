/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_dielect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:02:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 08:48:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf __attribute__((ALIGN,ARCH))
	*sp_object_mat_dielect(JSON_Object const *restrict mat,
		union u_hitables *restrict obj,
		const size_t obj_serial)
{
	t_material_sf	*m;

	(void)obj;
	NODO_R(json_object_has_value_of_type(mat, P_O_M_FUZZ, JSONNumber),
		ERRIN_N(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			P_O_MATERIAL " " P_O_M_FUZZ, E_INVALID), NULL);
	MEM(t_material_sf, m, 1UL, E_ALLOC);
	*m = material(DIELECTRIC, json_object_get_number(mat, P_O_M_FUZZ));
	return (m);
}
