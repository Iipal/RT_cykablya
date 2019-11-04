/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:46:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/04 12:44:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	s_get_current_object(JSON_Object const *obj_json,
				union u_hitables *obj,
				size_t const obj_serial)
{
	static t_fn_objs	fn_o[] = { sp_get_object_sphere, sp_get_object_cone,
		sp_get_object_cyiinder, sp_get_object_plane, sp_get_object_triangle };
	static char	const	*o_types[] = { P_OT_SPHERE, P_OT_CONE, P_OT_CYLINDER,
											P_OT_PLANE, P_OT_TRIANGLE };
	char const			*o_type = json_object_get_string(obj_json, P_O_TYPE);
	size_t				i;

	i = ~0UL;
	NODO_F(o_type, ERRIN_N(P_OBJECTS, obj_serial + 1, P_O_TYPE, E_INVALID));
	while (ARR_SIZE(fn_o) > ++i)
		if (!ft_strcmp(o_type, o_types[i]))
			return (fn_o[i](obj_json, obj, obj_serial));
	ERRIN_N(P_OBJECTS, obj_serial + 1, o_type, E_INVALID_O_TYPE);
	return (false);
}

bool	sp_get_objects(JSON_Object const *root, t_scene *const scene)
{
	JSON_Value const	*o = json_object_get_value(root, P_OBJECTS);
	JSON_Array			*o_arr;
	JSON_Object			*o_json;
	size_t				i;
	size_t				in_scene_objs;

	i = 0UL;
	NODO_F(o, ERRIN(P_OBJECTS, E_NO_OBJS));
	IFDO_F(JSONArray != json_value_get_type(o), ERRIN(P_OBJECTS, E_JARR_FMT));
	NODO_F(o_arr = json_value_get_array(o), ERRIN(P_OBJECTS, E_JARR_FMT));
	NODO_F(in_scene_objs = json_array_get_count(o_arr),
		ERRIN(P_OBJECTS, E_NO_OBJS));
	MEM(union u_hitables, scene->objs, in_scene_objs + 1UL, E_ALLOC);
	*scene->objs = (union u_hitables) { GENERIC, in_scene_objs, 0, 0 };
	while (in_scene_objs > ++i)
	{
		NODO_F(o_json = json_array_get_object(o_arr, i),
			ERRIN_N(P_OBJECTS, i, E_JARR_FMT, ", " E_INVALID));
		NO_F(s_get_current_object(o_json, &scene->objs[i], i - 1UL));
	}
	return (true);
}
