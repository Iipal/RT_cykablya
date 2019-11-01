/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_screen_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:29:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 10:49:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_screen_size(JSON_Object const *root, t_scene *const scene)
{
	NODO_F(json_object_has_value_of_type(root, P_SCREEN_W, JSONNumber),
		ERRIN_I(E_IN_SCREEN_SIZE, P_SCREEN_W));
	NODO_F(json_object_has_value_of_type(root, P_SCREEN_H, JSONNumber),
		ERRIN_I(E_IN_SCREEN_SIZE, P_SCREEN_H));
	scene->screen_w = json_object_get_number(root, P_SCREEN_W);
	scene->screen_h = json_object_get_number(root, P_SCREEN_H);
	return (true);
}
