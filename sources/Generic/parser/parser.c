/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:50:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/31 19:51:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene	*scene_parser(char *file)
{
	JSON_Value		*root;
	JSON_Object		*obj;
	t_scene *const	out = (t_scene*)malloc(sizeof(t_scene));
	int	fd;

	ft_memset(out, 0, sizeof(t_scene));
	root = json_parse_file(file);
	obj = json_value_get_object(root);
	IFDOMR(E_SYNTAX, !root || !obj, json_value_free(root), scene_free(out));
	NODO_R(out->cam = sp_render_camera(obj), json_value_free(root),
		scene_free(out));
	return out;
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
