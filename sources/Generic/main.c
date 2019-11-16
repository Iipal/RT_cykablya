/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 01:42:29 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 01:42:32 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# define TRDS 8UL
# include "thread_pool.h"
# include "render.h"
# include "attributes.h"
# include "parser.h"
# include "libft.h"
# include "Generic/libftsdl.h"
#endif

/*
** ──────────────────────────────────
** ───────▄██████████████████▄───────
** ────▄███████████████████████▄─────
** ───███████████████████████████────
** ──█████████████████████████████───
** ─████████████▀─────────▀████████──
** ██████████▀───────────────▀██████─
** ███████▀────────────────────█████▌
** ██████───▄▀▀▀▀▄──────▄▀▀▀▀▄──█████
** █████▀──────────────────▄▄▄───████
** ████────▄█████▄───────▄█▀▀▀█▄──██▀
** ████──▄█▀────▀██─────█▀────────█▀─
** ─▀██───────────▀────────▄███▄──██─
** ──██───▄▄██▀█▄──▀▄▄▄▀─▄██▄▀────███
** ▄███────▀▀▀▀▀──────────────▄▄──██▐
** █▄▀█──▀▀▀▄▄▄▀▀───────▀▀▄▄▄▀────█▌▐
** █▐─█────────────▄───▄──────────█▌▐
** █▐─▀───────▐──▄▀─────▀▄──▌─────██▐
** █─▀────────▌──▀▄─────▄▀──▐─────██▀
** ▀█─█──────▐─────▀▀▄▀▀─────▌────█──
** ─▀█▀───────▄────────────▄──────█──
** ───█─────▄▀──▄█████████▄─▀▄───▄█──
** ───█────█──▄██▀░░░░░░░▀██▄─█──█───
** ───█▄───▀▄──▀██▄█████▄██▀─▄▀─▄█───
** ────█▄────▀───▀▀▀▀──▀▀▀──▀──▄█────
** ─────█▄────────▄▀▀▀▀▀▄─────▄█─────
** ──────███▄──────────────▄▄██──────
** ─────▄█─▀█████▄▄────▄▄████▀█▄─────
** ────▄█───────▀▀██████▀▀─────█▄────
** ───▄█─────▄▀───────────▀▄────█▄───
** ──▄█─────▀───────────────▀────█▄──
** ──────────────────────────────────
** ▐▌▐█▄█▌▐▀▀█▐▀▀▌─█▀─█▀─▐▌▐▀█▐▀█─█─█
** ▐▌▐─▀─▌▐▀▀▀▐──▌─▀█─▀█─▐▌▐▀▄▐▀▄─█─█
** ▐▌▐───▌▐───▐▄▄▌─▄█─▄█─▐▌▐▄█▐─█─█▄█
** ──────────────────────────────────
** ──▐▀█ █─█▐▀▀▌─█ █ █▐▀▀▌▐▀█▐ █─█▀──
** ──▐▀▄ █─█ ▐▌──█ █ █▐──▌▐▀▄▐▀▄─▀█──
** ──▐▄█ █▄█ ▐▌──▀▄█▄▀▐▄▄▌▐─█▐ █ ▄█──
** ──────────────────────────────────
*/

static void __attribute__((ALIGN,ARCH))
	sdl_loop(struct s_tpool *restrict render_pool,
			struct s_sdl *restrict wnd,
			struct s_render_params *restrict params)
{
	SDL_Event		event;
	const Uint32	window_id = SDL_GetWindowID(wnd->w);

	while (-42)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				_Exit(0);
			else if ((event.type == SDL_KEYDOWN)
			&& (event.key.keysym.sym == SDLK_ESCAPE))
				_Exit(0);
			else
				continue ;
		}
		SDL_UpdateWindowSurface(wnd->w);
	}
	tpool_wait(render_pool);
	tpool_destroy(render_pool);
	sdl_free((struct s_sdl **restrict)&wnd);
	free(params);
}

static void __attribute__((ALIGN,ARCH))
	render_loop(
			struct s_scene	*restrict s,
			struct s_tpool *restrict render_pool,
			struct s_sdl *restrict wnd,
			struct s_render_params *restrict params)
{
	const size_t	render_tasks = TRDS << 2UL;
	const size_t	render_part = (s->render.w * s->render.h / render_tasks);
	register size_t	i;

	i = ~0UL;
	while (++i < render_tasks)
	{
		params[i] = (struct s_render_params){
			wnd->pxls, s->render.w, s->render.h, 1UL,
			render_part * i, render_part * (i + 1), s->objs,
			s->render.samples, s->cam.look_from, s->cam.look_at,
			s->cam.position, s->cam.fov,
			(float)s->render.w / (float)s->render.h,
			s->cam.aperture, s->cam.dist_to_focus, s->is_gi, 0 };
		tpool_add_work(render_pool, (void(*)(void*))s->render.fn, params + i);
	}
}

int __attribute__((ALIGN,ARCH))
	main(int argc, char *argv[])
{
	struct s_scene	*restrict			s;
	struct s_sdl	*restrict			wnd;
	struct s_render_params	*restrict	params;
	struct s_tpool	*restrict			render_pool;

	if (1 < (--argc) || !(++argv))
	{
		ft_putendl_fd("You must to give me a only 1 .json file.", 2);
		_Exit(EXIT_FAILURE);
	}
	if (!(s = scene_parser(*argv)))
		_Exit(EXIT_FAILURE);
	if (!(wnd = (__typeof__(wnd))(valloc(sizeof(*wnd)))))
		_Exit(EXIT_FAILURE);
	*wnd = (struct s_sdl){ 0 };
	if (!sdl_init(wnd, s->render.w, s->render.h, "RT_cykablyat'"))
		_Exit(EXIT_FAILURE);
	if (!(params = valloc((sizeof(*params)) * (TRDS << 2UL))))
		_Exit(EXIT_FAILURE);
	if (!(render_pool = tpool_create(TRDS)))
		_Exit(EXIT_FAILURE);
	render_loop(s, render_pool, wnd, params);
	sdl_loop(render_pool, wnd, params);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
