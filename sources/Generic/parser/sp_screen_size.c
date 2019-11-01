/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_screen_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:29:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 15:43:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_screen_size(JSON_Object const *root, t_scene *const scene)
{
	JSON_Object const	*s_size = json_object_dotget_object(root, P_SCREEN);

	NODO_F(s_size, ERRIN_I(E_IN_P_SCREEN, P_SCREEN));
	NODO_F(json_object_has_value_of_type(s_size, P_SCREEN_W, JSONNumber),
		ERRIN_I(E_IN_P_SCREEN_SIZE, P_SCREEN_W));
	NODO_F(json_object_has_value_of_type(s_size, P_SCREEN_H, JSONNumber),
		ERRIN_I(E_IN_P_SCREEN_SIZE, P_SCREEN_H));
	scene->screen_w = json_object_get_number(s_size, P_SCREEN_W);
	scene->screen_h = json_object_get_number(s_size, P_SCREEN_H);
	return (true);
}
