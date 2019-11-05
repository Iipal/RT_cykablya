/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_material.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:10:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 15:42:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline char	*s_get_mat_name(JSON_Object const *mat,
						size_t const obj_serial)
{
	char const	*mat_type = NULL;

	NODO_F(mat, ERRIN_N(P_OT_SPHERE, obj_serial + 1, P_O_MATERIAL, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(mat, P_O_M_TYPE, JSONString),
		ERRIN_N(P_OT_SPHERE, obj_serial + 1,
			P_O_MATERIAL " " P_O_TYPE, E_INVALID));
	mat_type = json_object_get_string(mat, P_O_M_TYPE);
	return ((char*)mat_type);
}

t_material_sf		*sp_get_object_material(JSON_Object const *obj_json,
						union u_hitables *obj,
						size_t const obj_serial)
{
	enum e_material		i;
	JSON_Object const	*mat = json_object_get_object(obj_json, P_O_MATERIAL);
	char const *const	mat_name = s_get_mat_name(mat, obj_serial);
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
