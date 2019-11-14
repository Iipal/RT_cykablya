/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:50:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 21:24:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	s_check_gi(JSON_Object *obj)
{
	bool	ret;

	ret = true;
	if (json_object_has_value_of_type(obj, P_GI, JSONBoolean))
		ret = json_object_get_boolean(obj, P_GI);
	return (ret);
}

struct s_scene __attribute__((ALIGN,ARCH))
	*scene_parser(const char *restrict file)
{
	JSON_Value		*root;
	JSON_Object		*obj;
	struct s_scene	*out;

	root = json_parse_file(file);
	obj = json_value_get_object(root);
	MEM(struct s_scene, out, 1UL, E_ALLOC);
	out->is_gi = s_check_gi(obj);
	IFDOMR(E_SYNTAX, !root || !obj, json_value_free(root), scene_free(out));
	NODO_R(sp_get_render_type(obj, &out->render), json_value_free(root),
		scene_free(out));
	NODO_R(sp_get_render_camera(obj, &out->cam), json_value_free(root),
		scene_free(out));
	if ((out->objs = sp_get_random_objects(obj)))
		out->objs->generic.self = (void*)out->is_gi;
	IFDO_R(out->objs, json_value_free(root), out);
	NODO_R(sp_get_objects(obj, out), json_value_free(root), scene_free(out));
	json_value_free(root);
	return (out);
}
