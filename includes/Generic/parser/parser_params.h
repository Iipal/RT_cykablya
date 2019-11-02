/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_params.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:21:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/02 18:36:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PARAM_NAMES_H
# define PARSER_PARAM_NAMES_H

# define P_RENDER        "render_type"
# define P_R_STD         "std"
# define P_R_NORMAL      "normal"
# define P_R_FULL        "full"

# define P_SCREEN        "screen"
# define P_S_WIDTH       "width"
# define P_S_HEIGHT      "height"

# define P_LIGHTS        "lights"

# define P_OBJECTS       "objects"

# define P_O_TYPE		 "type"
# define P_O_SPHERE      "sphere"

# define P_O_MATERIAL    "material"

# define P_O_M_TYPE      "type"
# define P_O_MT_NORMAL   "normal"
# define P_O_MT_LAMBERT  "lambertian"
# define P_O_MT_METAL    "metal"
# define P_O_MT_DIELECT  "dielectric"

# define P_O_M_ALBEDO    "albedo"
# define P_O_M_FUZZ      "fuzz"
# define P_O_POSITION    "pos"
# define P_O_RADIUS      "radius"

# define P_CAMERA        "camera"

# define P_C_LOOK_FROM     "look_from"
# define P_C_LOOK_AT       "look_at"
# define P_C_POSITION      "pos"

# define P_C_FOV           "fov"
# define P_C_FOV_MAX       360.0f
# define F_C_FOV_MIN       1.0f

# define P_C_APERTURE      "aperture"
# define P_C_DIST_TO_FOCUS "dist_to_focus"

#endif
