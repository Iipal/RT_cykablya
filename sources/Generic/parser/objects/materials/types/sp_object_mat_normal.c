/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:01:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/09 20:40:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf __attribute__((ALIGN,ARCH))
	*sp_object_mat_normal(const JSON_Object *restrict mat,
		const size_t obj_serial)
{
	t_material_sf	*m;

	IFDOR(1 != json_object_get_count(mat),
		ERRIN_D(P_OBJECTS " " P_O_MATERIAL, obj_serial + 1,
			E_INVALID_COUNT, E_DEF_PARAM(1)), NULL);
	MEM(t_material_sf, m, 1UL, E_ALLOC);
	*m = material(NORMAL, (t_v3sf){ 0.0, 0.0, 0.0 });
	return (m);
}
