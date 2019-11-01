/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errno.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:44:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 08:31:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_ERRNO_H
# define PARSER_ERRNO_H

# define E_PREFIX "RT parser ERROR"

# define E_SYNTAX "Invalid .json scene-file syntax or file doesn't exist."

# define E_IN_SCREEN_SIZE "in screen size params"

# define E_NO_CAM "Any camera in a scene wasn't founded."
# define E_IN_CAM "in camera object"

# define E_VEC_FMT "wrong vector format"

# define E_INVALID "invalid or missing"

# define ERRIN_N(at, n, e, m) ft_printf(E_PREFIX": %s:[%d] '%s' %s\n",at,n,e,m)
# define ERRIN(e, m) ft_printf(E_PREFIX": %s: '%s' "E_INVALID".\n",e, m)

#endif
