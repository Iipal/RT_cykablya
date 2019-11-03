/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:50:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/03 11:42:18 by tmaluh           ###   ########.fr       */
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
	MEM(t_scene, out, 1UL, E_ALLOC);
	IFDOMR(E_SYNTAX, !root || !obj, json_value_free(root), scene_free(out));
	NODO_R(sp_get_render_type(obj, &out->render), json_value_free(root),
		scene_free(out));
	NODO_R(sp_get_render_camera(obj, &out->cam), json_value_free(root),
		scene_free(out));
	NODO_R(sp_get_objects(obj, out), json_value_free(root), scene_free(out));
	NODO_R(sp_get_lights(obj, out), json_value_free(root), scene_free(out));
	return out;
}
