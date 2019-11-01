/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:50:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 10:59:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_scene	*scene_parser(char *file)
{
	JSON_Value	*root;
	JSON_Object	*obj;
	t_scene		*out;

	root = json_parse_file(file);
	obj = json_value_get_object(root);
	out = (t_scene*)ft_memalloc(sizeof(*out));
	IFDOMR(E_SYNTAX, !root || !obj, json_value_free(root), scene_free(out));
	sp_render_type(obj, &out->render_fn);
	NODO_R(sp_screen_size(obj, out), json_value_free(root), scene_free(out));
	NODO_R(sp_render_camera(&out->cam, obj), json_value_free(root),
		scene_free(out));
	return out;
}
