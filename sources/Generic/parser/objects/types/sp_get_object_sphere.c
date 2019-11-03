/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_object_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:01:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/03 22:29:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	s_validate_sphere_data(JSON_Object const *obj_json,
				size_t const obj_serial)
{
	NODO_F(json_object_has_value_of_type(obj_json, P_O_POSITION, JSONArray),
		ERRIN_N(P_OT_SPHERE, obj_serial + 1, P_O_POSITION, E_TYPE_FMT));
	NODO_F(json_object_has_value_of_type(obj_json, P_O_RADIUS, JSONNumber),
		ERRIN_N(P_OT_SPHERE, obj_serial + 1, P_O_RADIUS, E_TYPE_FMT));
	return (true);
}

bool		sp_get_object_sphere(JSON_Object const *obj_json,
				t_object *const obj,
				size_t const obj_serial)
{
	struct s_spheres	*s;

	s = NULL;
	NO_F(sp_get_object_material(obj_json, obj, obj_serial));
	NO_F(s_validate_sphere_data(obj_json, obj_serial));
	s = (struct s_spheres*)ft_memalloc(sizeof(struct s_spheres));
	MEM(struct s_spheres, s, 1UL, E_ALLOC);
	s->
	*s = (struct s_spheres) {  }
	obj->shape = (void*)s;
	return (true);
}
