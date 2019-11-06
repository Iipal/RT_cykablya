/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 16:07:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool __attribute__((ALIGN,ARCH))
	sp_get_lights(JSON_Object const *root, t_scene *const scene)
{
	JSON_Value const	*l = json_object_get_value(root, P_LIGHTS);
	JSON_Array			*l_arr;
	size_t				i;

	NODO_F(l, ERRIN_I(E_IN_LIGHTS, P_LIGHTS));
	IFDO_F(JSONArray != json_value_get_type(l), ERRIN(E_IN_LIGHTS, E_JARR_FMT));
	return (true);
}
