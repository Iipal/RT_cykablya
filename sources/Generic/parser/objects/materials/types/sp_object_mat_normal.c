/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:01:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 10:04:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf		*sp_object_mat_normal(JSON_Object const *mat,
						union u_hitables *restrict obj,
						size_t const obj_serial)
{
	return (sp_object_mat_metal(mat, obj, obj_serial));
}
