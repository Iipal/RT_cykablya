/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_material.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:10:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/03 01:20:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_get_object_material(JSON_Object const *mat,
			char const *mat_name,
			t_object *const obj,
			size_t const obj_serial)
{
	enum e_material		i;
	static t_fn_mats	fn_mats[] = { sp_object_mat_normal,
									sp_object_mat_lambert,
									sp_object_mat_metal,
									sp_object_mat_dielect };
	static char			*valid_mats[] = { P_O_MT_NORMAL, P_O_MT_LAMBERT,
											P_O_MT_METAL, P_O_MT_DIELECT };

	i = MATERIAL_START;
	while (MATERIAL_END > ++i)
		if (!ft_strcmp(mat_name, valid_mats[i - 1]))
		{
			obj->material_type = i;
			return (fn_mats[i - 1](mat, obj, obj_serial));
		}
	ERRIN_N(P_OBJECTS " " P_O_MATERIAL,
		obj_serial + 1, mat_name, E_INVALID_O_MAT);
	return (false);
}
