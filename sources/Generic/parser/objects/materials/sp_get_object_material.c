/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_material.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:10:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/02 18:38:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_get_object_material(JSON_Object const *mat,
			char const *mat_name,
			t_object *const obj,
			size_t const obj_serial)
{
	static t_fn_mats	fn_mats[] = { sp_object_mat_metal };
	static char			*valid_mats[] = { P_O_MT_METAL };
	enum e_material		i;

	i = -1;
	while (1 > ++i)
		if (!ft_strcmp(mat_name, valid_mats[i]))
			return (fn_mats[i](mat, obj, obj_serial));
	ERRIN_N(P_O_MATERIAL, obj_serial + 1, P_O_TYPE, E_INVALID);
	return (false);
}
