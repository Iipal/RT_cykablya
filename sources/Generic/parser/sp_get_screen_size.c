/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_screen_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:29:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/02 15:50:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_get_screen_size(JSON_Object const *root,
								size_t *const w,
								size_t *const h)
{
	JSON_Object const	*s_size = json_object_dotget_object(root, P_SCREEN);

	NODO_F(s_size, ERRIN_I(P_SCREEN, P_SCREEN));
	NODO_F(json_object_has_value_of_type(s_size, P_S_WIDTH, JSONNumber),
		ERRIN_I(E_IN_SCREEN_SIZE, P_S_WIDTH));
	NODO_F(json_object_has_value_of_type(s_size, P_S_HEIGHT, JSONNumber),
		ERRIN_I(E_IN_SCREEN_SIZE, P_S_HEIGHT));
	*w = json_object_get_number(s_size, P_S_WIDTH);
	*h = json_object_get_number(s_size, P_S_HEIGHT);
	return (true);
}
