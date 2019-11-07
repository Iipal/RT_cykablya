/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:01:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 08:41:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf __attribute__((ALIGN,ARCH))
	*sp_object_mat_normal(const JSON_Object *restrict mat,
		union u_hitables *restrict obj,
		const size_t obj_serial)
{
	return (sp_object_mat_metal(mat, obj, obj_serial));
}
