/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_render_camera.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:17:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/02 15:53:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline bool	s_validate_camera_data(JSON_Object const *obj)
{
	NODO_F(json_object_has_value_of_type(obj, P_C_LOOK_FROM, JSONArray),
		ERRIN_I(P_CAMERA, P_C_LOOK_FROM));
	NODO_F(json_object_has_value_of_type(obj, P_C_LOOK_AT, JSONArray),
		ERRIN_I(P_CAMERA, P_C_LOOK_AT));
	NODO_F(json_object_has_value_of_type(obj, P_C_POSITION, JSONArray),
		ERRIN_I(P_CAMERA, P_C_POSITION));
	NODO_F(json_object_has_value_of_type(obj, P_C_FOV, JSONNumber),
		ERRIN_I(P_CAMERA, P_C_FOV));
	NODO_F(json_object_has_value_of_type(obj, P_C_APERTURE, JSONNumber),
		ERRIN_I(P_CAMERA, P_C_APERTURE));
	NODO_F(json_object_has_value_of_type(obj, P_C_DIST_TO_FOCUS, JSONNumber),
		ERRIN_I(P_CAMERA, P_C_DIST_TO_FOCUS));
	return (true);
}

bool				sp_get_render_camera(JSON_Object const *root,
						struct s_render_params *const dst)
{
	JSON_Object const	*cam = json_object_get_object(root, P_CAMERA);

	NOM_F(E_NO_CAM, cam);
	NO_F(s_validate_camera_data(cam));
	NO_F(sp_get_v3sf_arr(&dst->look_from,
		json_object_get_array(cam, P_C_LOOK_FROM), P_C_LOOK_FROM, 0UL));
	NO_F(sp_get_v3sf_arr(&dst->look_at,
		json_object_get_array(cam, P_C_LOOK_AT), P_C_LOOK_AT, 0UL));
	NO_F(sp_get_v3sf_arr(&dst->position,
		json_object_get_array(cam, P_C_POSITION), P_C_POSITION, 0UL));
	dst->fov = json_object_get_number(cam, P_C_FOV);
	dst->aperture = json_object_get_number(cam, P_C_APERTURE);
	dst->dist_to_focus = json_object_get_number(cam, P_C_DIST_TO_FOCUS);
	return (true);
}