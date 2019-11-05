/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_object_mat_dielect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 01:02:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 15:40:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_material_sf	*sp_object_mat_dielect(JSON_Object const *mat,
			union u_hitables *obj,
			size_t const obj_serial)
{
	t_material_sf	*m;

	MEM(t_material_sf, m, 1UL, E_ALLOC);
	return (m);
}
