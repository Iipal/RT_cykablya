/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_render_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:24:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 15:46:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_get_render_type(JSON_Object const *root, t_fnptr_render *fn)
{
	int8_t					i;
	char const				*rtype;
	bool					is_valid_type;
	t_fnptr_render const	valid_renders[] = { render_normal, render_full };
	char const				*valid_rtypes[] = { P_RENDER_STD,
												P_RENDER_NORMAL,
												P_RENDER_FULL };

	i = -1;
	*fn = render_std;
	is_valid_type = false;
	NODO_F(json_object_has_value_of_type(root, P_RENDER, JSONString),
		ERRIN(E_IN_RENDER_TYPE, E_INVALID_RTYPE));
	NODO_F(rtype = json_object_get_string(root, P_RENDER),
		ERRIN(E_IN_RENDER_TYPE, E_INVALID_RTYPE));
	while ((sizeof(valid_rtypes) / sizeof(*valid_rtypes)) > ++i)
		if (!ft_strcmp(valid_rtypes[i], rtype))
		{
			if (i)
				*fn = valid_renders[i - 1];
			is_valid_type = true;
			break ;
		}
	NODO_F(is_valid_type, ERRIN(E_IN_RENDER_TYPE, E_INVALID_RTYPE));
	return (is_valid_type);
}
