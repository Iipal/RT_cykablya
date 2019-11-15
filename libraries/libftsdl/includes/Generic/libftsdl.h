/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 22:34:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_H
# define LIBFTSDL_H

# include "libftsdl_errno.h"
# include "libftsdl_macroses.h"

# include <stdbool.h>
# include <stdint.h>

# if defined __APPLE__
#  include "SDL.h"
#  include "SDL_image.h"
#  include "SDL_ttf.h"
# elif defined (__linux__)
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
#  include <SDL2/SDL_ttf.h>
# else
#  error "Unsupported OS. Try to compile this on MacOS or Linux"
# endif

struct		s_sdl
{
	SDL_Window	*w;
	SDL_Surface	*wsurf;
	uint32_t	*pxls;
	TTF_Font	*font;
	SDL_Event	e;
};

# define SDL typedef struct s_sdl Sdl

SDL;

/*
**	Initialize SDL2.
**	\param sdl: Pointer to already allocated Sdl.
**	\param width: Window width what will created.
**	\param height: Window height what will created.
**	\param title: Title for window.
*/
bool		sdl_init(Sdl *restrict sdl,
				int32_t width,
				int32_t height,
				const char *restrict title);

bool		sdl_create_window(Sdl *restrict sdl,
				int32_t width,
				int32_t height,
				const char *restrict title);
bool		sdl_create_window_borderless(Sdl *restrict sdl,
				int32_t width,
				int32_t height,
				const char *restrict title);
/*
**	Free all data in Sdl*.
*/
void		sdl_free(Sdl **restrict sdl);
/*
**	mlx_pixelput implementation on SDL2 for copy workflow from MLX library:
**	\param surf: Surface in which will set color \param clr.
**	\param x: X position in surface->pixels.
**	\param y: Y position in surface->pixels.
**	\param clr: Color which will set on
**	 \param x \param y position in \param surf.
**
**	Protected if \param surf doesn't exit and from segfault when position
**	 \param x && \param y isn't on \param surf.
*/
extern void	sdl_pixelput(SDL_Surface *restrict surf,
				register const int32_t x,
				register const int32_t y,
				register const uint32_t clr);
SDL_Surface	*sdl_load_image(const char *restrict path,
				const SDL_PixelFormat *restrict format);
SDL_Surface	*sdl_load_font(const Sdl *restrict sdl,
				const char *restrict text,
				SDL_Color text_color);
#endif
