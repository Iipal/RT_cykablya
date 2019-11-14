/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:57:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 08:27:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool __attribute__((ALIGN,ARCH))
	sp_get_lights(const JSON_Object *restrict root,
		struct s_scene *restrict scene)
{
	const JSON_Value	*l = json_object_get_value(root, P_LIGHTS);
	JSON_Array			*l_arr;
	size_t				i;

	(void)l_arr;
	(void)i;
	(void)scene;
	NODO_F(l, ERRIN_I(E_IN_LIGHTS, P_LIGHTS));
	IFDO_F(JSONArray != json_value_get_type(l), ERRIN(E_IN_LIGHTS, E_JARR_FMT));
	return (true);
}
