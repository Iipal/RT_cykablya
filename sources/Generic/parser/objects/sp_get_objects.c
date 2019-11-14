/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:46:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 22:09:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool __attribute__((ALIGN,ARCH))
	s_get_current_object(const JSON_Object *obj_json,
		union u_hitables *restrict obj,
		const size_t obj_serial)
{
	static t_fn_objs	o_fns[] = { sp_get_object_sphere, sp_get_object_cone,
		sp_get_object_cylinder, sp_get_object_plane, sp_get_object_triangle };
	static const char	*o_types[] = { P_OT_SPHERE, P_OT_CONE, P_OT_CYLINDER,
											P_OT_PLANE, P_OT_TRIANGLE };
	const char			*o_type = json_object_get_string(obj_json, P_O_TYPE);
	size_t				i;

	i = ~0UL;
	NODO_F(o_type, ERRIN_N(P_OBJECTS, obj_serial + 1, P_O_TYPE, E_INVALID));
	while (ARR_SIZE(o_fns) > ++i)
		if (!ft_strcmp(o_type, o_types[i]))
			return (o_fns[i](obj_json, obj, obj_serial));
	ERRIN_N(P_OBJECTS, obj_serial + 1, o_type, E_INVALID_O_TYPE);
	return (false);
}

bool __attribute__((ALIGN,ARCH))
	sp_get_objects(const JSON_Object *restrict root,
		struct s_scene *restrict s)
{
	const JSON_Value	*o = json_object_get_value(root, P_OBJECTS);
	JSON_Array			*o_arr;
	JSON_Object			*o_json;
	size_t				s_objs;
	size_t				i;

	i = ~0UL;
	NODO_F(o, ERRIN(P_OBJECTS, E_NO_OBJS));
	IFDO_F(JSONArray != json_value_get_type(o), ERRIN(P_OBJECTS, E_JARR_FMT));
	NODO_F(o_arr = json_value_get_array(o), ERRIN(P_OBJECTS, E_JARR_FMT));
	NODO_F(s_objs = spu_value_inrange(
		json_array_get_count(o_arr), 0, P_O_MAX), ERRIN(P_OBJECTS, E_NO_OBJS));
	MEM(union u_hitables, s->objs, s_objs + 1UL, E_ALLOC);
	*s->objs = (union u_hitables){{ GENERIC, s_objs + 1, (void*)s->is_gi, 0 }};
	while (s_objs > ++i)
	{
		NODO_F(o_json = json_array_get_object(o_arr, i),
			ERRIN_N(P_OBJECTS, i, E_JARR_FMT, ", " E_INVALID));
		NO_F(s_get_current_object(o_json, &s->objs[i + 1UL], i));
	}
	return (true);
}
