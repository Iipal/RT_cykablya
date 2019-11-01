/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:50:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 15:56:48 by tmaluh           ###   ########.fr       */
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
	sp_get_render_type(obj, &out->render_fn);
	NODO_R(sp_get_screen_size(obj, &out->screen_w, &out->screen_h),
		json_value_free(root), scene_free(out));
	NODO_R(sp_get_render_camera(obj, &out->cam), json_value_free(root),
		scene_free(out));
	NODO_R(sp_get_lights(obj, out), json_value_free(root), scene_free(out));
	return out;
}
