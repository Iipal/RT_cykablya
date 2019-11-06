/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_render_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:24:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 10:09:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern inline bool __attribute__((ARCH,INLINE))
	s_validate_render_data(JSON_Object const *r)
{
	IFDO_F(4 != json_object_get_count(r), ERRIN(E_IN_RENDER, E_DEF_PARAM(4)));
	NODO_F(json_object_has_value_of_type(r, P_RS_WIDTH, JSONNumber),
		ERRIN_I(E_IN_RENDER_SIZE, P_RS_WIDTH));
	NODO_F(json_object_has_value_of_type(r, P_RS_HEIGHT, JSONNumber),
		ERRIN_I(E_IN_RENDER_SIZE, P_RS_HEIGHT));
	NODO_F(json_object_has_value_of_type(r, P_R_SAMPLES, JSONNumber),
		ERRIN_I(E_IN_RENDER, P_R_SAMPLES));
	NODO_F(json_object_has_value_of_type(r, P_R_TYPE, JSONString),
		ERRIN(E_IN_RENDER_TYPE, E_INVALID_TYPE(P_RENDER)));
	return (true);
}

bool __attribute__((ALIGN,ARCH))
	sp_get_render_type(JSON_Object const *root,
						t_render *const render)
{
	int8_t					i;
	char const				*rtype;
	JSON_Object const		*r = json_object_get_object(root, P_RENDER);
	t_fnptr_render const	valid_renders[] = { render_normal, render_full };
	char const				*valid_rtypes[] = { P_RT_STD, P_RT_NORMAL,
												P_RT_FULL };

	i = -1;
	render->fn = render_std;
	NODO_F(r, ERRIN_I(E_INVALID_TYPE(P_RENDER), ""));
	NO_F(s_validate_render_data(r));
	NODO_F(rtype = json_object_get_string(r, P_R_TYPE),
		ERRIN(E_IN_RENDER_TYPE, E_INVALID_TYPE(P_RENDER)));
	render->w = json_object_get_number(r, P_RS_WIDTH);
	render->h = json_object_get_number(r, P_RS_HEIGHT);
	render->samples = json_object_get_number(r, P_R_SAMPLES);
	while ((sizeof(valid_rtypes) / sizeof(*valid_rtypes)) > ++i)
		if (!ft_strcmp(valid_rtypes[i], rtype))
		{
			render->fn = (i ? valid_renders[i - 1] : render_std);
			return (true);
		}
	ERRIN(E_IN_RENDER_TYPE, E_INVALID_TYPE(P_RENDER));
	return (false);
}
