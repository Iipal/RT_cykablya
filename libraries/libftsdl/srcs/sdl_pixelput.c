/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:02:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 22:34:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_pixelput(SDL_Surface *restrict surf,
				register const int32_t x,
				register const int32_t y,
				register const uint32_t clr)
{
	if (0 <= x && 0 <= y && y < surf->h && x < surf->w)
		((uint32_t*)(surf->pixels))[y * surf->w + x] = clr;
}
