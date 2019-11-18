/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_types_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:03:59 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 21:04:00 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TYPES_INTERNAL_H
# define RENDER_TYPES_INTERNAL_H

# ifndef S_RENDER_PARAMS
#  define S_RENDER_PARAMS

struct	s_render_params
{
	uint32_t		*restrict		screen;
	size_t							screen_width;
	size_t							screen_height;
	ptrdiff_t						step;
	ptrdiff_t						start;
	ptrdiff_t						stop;
	union u_hitables	*restrict	hitables;
	size_t							samples;
	t_v3sf							look_from;
	t_v3sf							look_at;
	t_v3sf							position;
	float							fov;
	float							aspect_ratio;
	float							aperture;
	float							dist_to_focus;
	_Bool							is_gi_enable;
	int								stub : __CHAR_BIT__ * 3;
};

# endif

#endif
