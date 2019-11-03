/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_render_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:24:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/03 13:15:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_get_render_type(JSON_Object const *root, t_render *const render)
{
	bool					is_valid_rtype;
	char const				*rtype;
	int8_t					i;
	JSON_Object const		*r = json_object_get_object(root, P_RENDER);
	t_fnptr_render const	valid_renders[] = { render_normal, render_full };
	char const				*valid_rtypes[] = { P_RT_STD,
												P_RT_NORMAL,
												P_RT_FULL };

	i = -1;
	is_valid_rtype = false;
	render->fn = render_std;
	NODO_F(r, ERRIN_I(E_INVALID_TYPE(P_RENDER), ""));
	NODO_F(json_object_has_value_of_type(r, P_R_TYPE, JSONString),
		ERRIN(E_IN_RENDER_TYPE, E_INVALID_TYPE(P_RENDER)));
	NODO_F(rtype = json_object_get_string(r, P_RENDER),
		ERRIN(E_IN_RENDER_TYPE, E_INVALID_TYPE(P_RENDER)));
	while ((sizeof(valid_rtypes) / sizeof(*valid_rtypes)) > ++i)
		if (!ft_strcmp(valid_rtypes[i], rtype))
		{
			if (i)
				render->fn = valid_renders[i - 1];
			is_valid_rtype = true;
			break ;
		}
	NODO_F(is_valid_rtype, ERRIN(E_IN_RENDER_TYPE, E_INVALID_TYPE(P_RENDER)));
	NO_F(sp_get_render_size(r, &render->w, &render->h));
	return (true);
}
