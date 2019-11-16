#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
#endif

# include "ray.h"
# include "sphere.h"
# include "thread_pool.h"
# include "render.h"
# include "material.h"
# include "attributes.h"

#include "scene_generator.h"

# include "random_float.h"
# include <assert.h>

# include "cone_constructor.h"
# include "cylinder_constructor.h"
# include "tetrahedron_constructor.h"
# include "plane_constructor.h"

# include "parser.h"
# include "libft.h"
# include "Generic/libftsdl.h"

static struct s_tpool __attribute__((ALIGN,ARCH))
	rendering_pool(
		struct s_tpool *restrict render_pool,
		struct s_sdl *restrict wnd,
		struct s_scene *restrict s,
		const size_t render_threads)
{
	const size_t	render_tasks = render_threads << 2UL;
	const size_t	render_part = (s->render.w * s->render.h / render_tasks);
	size_t			i;
	struct s_render_params	*restrict	params;

	if (!(params = (__typeof__(params))(valloc(sizeof(*params) * render_tasks))))
		_Exit(EXIT_FAILURE);
	if (!(render_pool = tpool_create(render_threads)))
		_Exit(EXIT_FAILURE);
	i = ~0UL;
	while (++i < render_tasks)
	{
		params[i] = (struct s_render_params){
			.screen_width = s->render.w, .screen_height = s->render.h,
			.start = render_part * i, .stop = render_part * (i + 1),
			.step = 1UL, .hitables = s->objs, .samples = s->render.samples,
			.screen = wnd->pxls, .look_from = s->cam.look_from,
			.look_at = s->cam.look_at, .position = s->cam.position,
			.fov = s->cam.fov, .aperture = s->cam.aperture,
			.aspect_ratio = (float)s->render.w / (float)s->render.h,
			.dist_to_focus = s->cam.dist_to_focus, .is_gi_enable = s->is_gi
		};
		tpool_add_work(render_pool, (void(*)(void*))s->render.fn, params + i);
	}
}

static void __attribute__((ALIGN,ARCH))
	sdl_loop(struct s_tpool *restrict render_pool,
			struct s_sdl *restrict wnd,
			struct s_render_params *restrict params)
{
	SDL_Event		event;
	const Uint32	window_id = SDL_GetWindowID(wnd->w);

	while (-42)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			_Exit(0);
		else if ((event.type == SDL_WINDOWEVENT)
		&& ((event.window.event == SDL_WINDOWEVENT_EXPOSED)
		|| (event.window.event == SDL_WINDOWEVENT_ENTER)
		|| (event.window.event == SDL_WINDOWEVENT_SHOWN)))
			SDL_UpdateWindowSurface(wnd->w);
		else if ((event.type == SDL_KEYDOWN)
		&& (event.key.keysym.sym == SDLK_ESCAPE))
			_Exit(0);
		else
			continue ;
	}
	tpool_wait(render_pool);
	tpool_destroy(render_pool);
	sdl_free((struct s_sdl **restrict)&wnd);
	free(params);
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

	const size_t				render_threads = 8UL;
	const size_t				render_tasks = render_threads << 2UL;
	const size_t				render_part = (s->render.w * s->render.h / render_tasks);

	if (!(params = valloc((sizeof(*params)) * render_tasks)))
		_Exit(EXIT_FAILURE);
	if (!(render_pool = tpool_create(render_threads)))
		_Exit(EXIT_FAILURE);

	size_t i;
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
	sdl_loop(render_pool, wnd, params);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
