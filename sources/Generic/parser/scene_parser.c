/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:50:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 08:49:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline bool	s_validate_screen_size_data(JSON_Object const *root,
						t_scene *const scene)
{
	NODO_F(json_object_has_value_of_type(root, P_SCREEN_W, JSONNumber),
		ERRIN(E_IN_SCREEN_SIZE, P_SCREEN_W));
	NODO_F(json_object_has_value_of_type(root, P_SCREEN_H, JSONNumber),
		ERRIN(E_IN_SCREEN_SIZE, P_SCREEN_H));
	scene->screen_w = json_object_get_number(root, P_SCREEN_W);
	scene->screen_h = json_object_get_number(root, P_SCREEN_H);
	return (true);
}

t_scene				*scene_parser(char *file)
{
	JSON_Value	*root;
	JSON_Object	*obj;
	t_scene		*out;

	root = json_parse_file(file);
	obj = json_value_get_object(root);
	out = (t_scene*)ft_memalloc(sizeof(*out));
	NO_R(s_validate_screen_size_data(obj, out), scene_free(out));
	IFDOMR(E_SYNTAX, !root || !obj, json_value_free(root), scene_free(out));
	NODO_R(sp_render_camera(&out->cam, obj), json_value_free(root),
		scene_free(out));
	return out;
}
