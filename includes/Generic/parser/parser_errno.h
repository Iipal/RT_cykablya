/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errno.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:44:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 16:07:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_ERRNO_H
# define PARSER_ERRNO_H

# define E_PREFIX "RT parser ERROR"

# define E_SYNTAX "Invalid .json scene-file syntax or file doesn't exist."

# define E_IN_RENDER_TYPE "in render type"
# define E_IN_P_SCREEN "in screen"
# define E_IN_P_SCREEN_SIZE "in screen params size"

# define E_IN_CAM "in camera"
# define E_NO_CAM "Any camera in a scene wasn't founded."

# define E_IN_LIGHTS "in lights"

# define E_INVALID_RTYPE "Invalid render type. Using \'std\' render by default"

# define E_VEC_FMT "wrong vector format"
# define E_JARR_FMT "wrong json array format"

# define E_INVALID "invalid or missing"

# define ERRIN_N(at, n, e, m) ft_printf(E_PREFIX": %s:[%d] '%s' %s\n",at,n,e,m)
# define ERRIN_I(e, m) ft_printf(E_PREFIX": %s: '%s' "E_INVALID".\n",e, m)
# define ERRIN(e, m) ft_printf(E_PREFIX": %s: %s.\n",e, m)

#endif
