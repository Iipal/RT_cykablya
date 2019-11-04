/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_render_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:29:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/04 08:58:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_get_render_size(JSON_Object const *root,
								size_t *const w,
								size_t *const h)
{
	NODO_F(json_object_has_value_of_type(root, P_S_WIDTH, JSONNumber),
		ERRIN_I(E_IN_SCREEN_SIZE, P_S_WIDTH));
	NODO_F(json_object_has_value_of_type(root, P_S_HEIGHT, JSONNumber),
		ERRIN_I(E_IN_SCREEN_SIZE, P_S_HEIGHT));
	*w = json_object_get_number(root, P_S_WIDTH);
	*h = json_object_get_number(root, P_S_HEIGHT);
	return (true);
}
