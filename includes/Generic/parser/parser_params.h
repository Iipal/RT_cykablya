/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_params.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:21:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 09:58:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PARAM_NAMES_H
# define PARSER_PARAM_NAMES_H

# define P_RENDER         "render"

# define P_R_TYPE        "type"
# define P_RT_STD        "std"
# define P_RT_NORMAL     "normal"
# define P_RT_FULL       "full"

# define P_R_SAMPLES     "samples"

# define P_R_SCREEN      "screen"
# define P_RS_WIDTH      "width"
# define P_RS_HEIGHT     "height"

# define P_LIGHTS        "lights"

# define P_OBJECTS       "objects"

# define P_O_TYPE		 "type"
# define P_OT_SPHERE     "sphere"
# define P_OT_CONE       "cone"
# define P_OT_PLANE      "plane"
# define P_OT_TRIANGLE   "triangle"
# define P_OT_CYLINDER   "cylinder"

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
# define P_O_HEIGHT      "height"
# define P_O_TOP         "top"

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
