/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:28:27 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 20:28:28 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include <stddef.h>
#  include "vector_types.h"
#  include "camera.h"
#  include "random_float.h"
#  include "hitable.h"
#  include "color_to_rgb.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include <stdint.h>
#  include "vector_types.h"
#  include "render_types_internal.h"

void __attribute__((ALIGN,ARCH))
render_std(struct s_render_params *restrict param);
void __attribute__((ALIGN,ARCH))
render_normal(struct s_render_params *restrict param);
void __attribute__((ALIGN,ARCH))
render_full(struct s_render_params *restrict param);

# endif
#endif
