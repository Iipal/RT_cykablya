/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_render_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:17:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/31 21:54:56 by tmaluh           ###   ########.fr       */
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

struct s_render_params	*sp_render_camera(JSON_Object *root)
{
	JSON_Object const		*cam = json_object_get_object(root, P_CAMERA);
	struct s_render_params	*out;

	out = NULL;
	NOM_R(E_NO_CAM, cam, out);
	NO_R(s_validate_camera_data(cam), out);
	out = (struct s_render_params*)ft_memalloc(sizeof(*out));
	NODO_F(sp_get_v3sf_arr(&out->position, json_object_get_array(cam,
		P_LOOK_FROM), P_LOOK_FROM, 0UL), FREE(out, free));
	NODO_F(sp_get_v3sf_arr(&out->position, json_object_get_array(cam,
		P_LOOK_AT), P_LOOK_AT, 0UL), FREE(out, free));
	NODO_F(sp_get_v3sf_arr(&out->position, json_object_get_array(cam,
		P_POSITION), P_POSITION, 0UL), FREE(out, free));
	out->fov = json_object_get_number(cam, P_FOV);
	out->aperture = json_object_get_number(cam, P_APERTURE);
	out->dist_to_focus = json_object_get_number(cam, P_DIST_TO_FOCUS);
	return (out);
}
