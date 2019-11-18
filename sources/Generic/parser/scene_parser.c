/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:50:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 13:22:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

struct s_scene __attribute__((ALIGN,ARCH))
	*scene_parser(const char *restrict file)
{
	JSON_Value		*root;
	JSON_Object		*obj;
	struct s_scene	*out;

	root = json_parse_file(file);
	obj = json_value_get_object(root);
	MEM(struct s_scene, out, 1UL, E_ALLOC);
	IFDOMR(E_SYNTAX, !root || !obj, json_value_free(root), scene_free(out));
	out->is_gi = sp_get_gi(obj);
	NODO_R(sp_get_render_type(obj, &out->render), json_value_free(root),
		scene_free(out));
	NODO_R(sp_get_render_camera(obj, &out->cam), json_value_free(root),
		scene_free(out));
	if ((out->objs = sp_get_random_objects(obj)))
		out->objs->generic.self = (void*)out->is_gi;
	else
		NODO_R(sp_get_objects(obj, out),
			json_value_free(root), scene_free(out));
	json_value_free(root);
	sp_post_validation(out);
	return (out);
}
