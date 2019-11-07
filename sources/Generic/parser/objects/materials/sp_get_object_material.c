/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_material.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:10:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 08:32:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern inline const char __attribute__((INLINE,ARCH))
	*s_get_mat_name(const JSON_Object *restrict mat,
					const size_t obj_serial)
{
	const char	*mat_type = NULL;

	NODO_F(mat, ERRIN_N(P_OT_SPHERE, obj_serial + 1, P_O_MATERIAL, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(mat, P_O_M_TYPE, JSONString),
		ERRIN_N(P_OT_SPHERE, obj_serial + 1,
			P_O_MATERIAL " " P_O_TYPE, E_INVALID));
	mat_type = json_object_get_string(mat, P_O_M_TYPE);
	return (mat_type);
}

t_material_sf __attribute__((ALIGN,ARCH))
	*sp_get_object_material(const JSON_Object *restrict obj_json,
							union u_hitables *restrict obj,
							const size_t obj_serial)
{
	enum e_material		i;
	const JSON_Object	*mat = json_object_get_object(obj_json, P_O_MATERIAL);
	const char *const	mat_name = s_get_mat_name(mat, obj_serial);
	static t_fn_mats	fn_mats[] = { sp_object_mat_normal,
		sp_object_mat_lambert, sp_object_mat_metal, sp_object_mat_dielect };
	static char			*valid_mats[] = { P_O_MT_NORMAL, P_O_MT_LAMBERT,
											P_O_MT_METAL, P_O_MT_DIELECT };

	NO_F(mat_name);
	i = MATERIAL_START;
	while (MATERIAL_END > ++i)
		if (!ft_strcmp(mat_name, valid_mats[i - 1]))
			return (fn_mats[i - 1](mat, obj, obj_serial));
	ERRIN_N(P_OBJECTS " " P_O_MATERIAL,
		obj_serial + 1, mat_name, E_INVALID_O_MAT);
	return (NULL);
}
