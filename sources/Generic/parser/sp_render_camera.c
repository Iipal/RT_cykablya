/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_render_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:17:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/31 19:31:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline bool		s_validate_camera_data(JSON_Object const *obj)
{
	NODO_F(json_object_has_value_of_type(obj, P_LOOK_FROM, JSONArray),
		ERRIN(E_IN_CAM, P_LOOK_FROM));
	NODO_F(json_object_has_value_of_type(obj, P_LOOK_AT, JSONArray),
		ERRIN(E_IN_CAM, P_LOOK_AT));
	NODO_F(json_object_has_value_of_type(obj, P_POSITION, JSONArray),
		ERRIN(E_IN_CAM, P_POSITION));
	NODO_F(json_object_has_value_of_type(obj, P_FOV, JSONNumber),
		ERRIN(E_IN_CAM, P_FOV));
	NODO_F(json_object_has_value_of_type(obj, P_DIST_TO_FOCUS, JSONNumber),
		ERRIN(E_IN_CAM, P_DIST_TO_FOCUS));
	return (true);
}

struct s_render_params	*sp_render_camera(JSON_Object *obj)
{
	JSON_Object const		*obj_cam = json_object_get_object(obj, P_CAMERA);
	struct s_render_params	*out;

	out = NULL;
	NOM_R(E_NO_CAM, obj_cam, out);
	NO_R(s_validate_camera_data(obj_cam), out);
	out = (struct s_render_params*)ft_memalloc(sizeof(*out));
	NO_F(sp_arr_to_v3sf(&out->position, json_object_get_array(obj, P_POSITION),
		P_POSITION, 0UL));
	return (out);
}
