/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errno.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:44:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/02 15:42:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_ERRNO_H
# define PARSER_ERRNO_H

# include "parser_params.h"

# define E_PREFIX "RT parser ERROR"

# define E_ALLOC E_PREFIX ": Memory allocating error. Where is memory, pal?"

# define E_SYNTAX "Invalid .json scene-file syntax or file doesn't exist."

# define E_IN_RENDER_TYPE "in render type"

# define E_IN_SCREEN "in " P_SCREEN
# define E_IN_SCREEN_SIZE "in " P_SCREEN " params"

# define E_NOT_FOUNDED(_what) "Any " _what " in a scene wasn't founded."

# define E_NO_CAM E_NOT_FOUNDED(P_CAMERA)

# define E_IN_LIGHTS "in lights"

# define E_NO_OBJS E_NOT_FOUNDED(P_OBJECTS)

# define E_INVALID_RTYPE "Invalid render type. Using \'std\' render by default"

# define E_VEC_FMT "wrong vector format"
# define E_JARR_FMT "wrong json array format"
# define E_TYPE_FMT "wrong json paramater format"

# define E_INVALID "invalid or missing"

# define ERRIN_N(at, n, e, m) ft_printf(E_PREFIX": %s [%d]: '%s' %s\n",at,n,e,m)
# define ERRIN_I(e, m) ft_printf(E_PREFIX": %s: '%s' "E_INVALID".\n",e, m)
# define ERRIN(e, m) ft_printf(E_PREFIX": %s: %s.\n",e, m)

#endif
