#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
#endif

# include <MiniFB.h>
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

int __attribute__((ALIGN,ARCH))
	main(int argc, char *argv[])
{
	struct s_scene	*s;

	--argc;
	++argv;
	if (1 < argc || !argc)
	{
		ft_putendl_fd("You must to give me a only 1 .json file.", 2);
		return (EXIT_FAILURE);
	}
	clock_t	start, end;
	start = clock();
	if (!(s = scene_parser(*argv)))
		return (EXIT_FAILURE);
	end = clock();
	printf("parse time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	const size_t				render_threads = 8UL;
	const size_t				render_tasks = render_threads << 2UL;
	const size_t				render_part =
		(s->render.w * s->render.h / render_tasks);
	struct s_tpool	*restrict	render_pool;

	struct s_sdl	*restrict	wnd;
	if (!(wnd = (__typeof__(wnd))(valloc(sizeof(*wnd)))))
		return (-1);
	*wnd = (struct s_sdl){ 0 };

	printf("STATUS:%d\n", sdl_init(wnd, s->render.w, s->render.h, "BLYAT'"));

	struct s_render_params	*restrict	Params = valloc((sizeof(*Params)) * render_tasks);
	render_pool = tpool_create(render_threads);

	for (size_t i = 0; i < render_tasks; i++)
	{
		Params[i].screen_width = s->render.w;
		Params[i].screen_height = s->render.h;
		Params[i].start = render_part * i;
		Params[i].stop = render_part * (i + 1);
		Params[i].step = 1UL;
		Params[i].hitables = s->objs;
		Params[i].samples = s->render.samples;
		Params[i].screen = wnd->pxls;
		Params[i].look_from = s->cam.look_from;
		Params[i].look_at = s->cam.look_at;
		Params[i].position = s->cam.position;
		Params[i].fov = s->cam.fov;
		Params[i].aspect_ratio = (float)s->render.w / (float)s->render.h;
		Params[i].aperture = s->cam.aperture;
		Params[i].dist_to_focus = s->cam.dist_to_focus;
		Params[i].is_gi_enable = s->is_gi;
		tpool_add_work(render_pool, (void(*)(void*))s->render.fn,
			Params + i);
	}

	_Bool	running;
	running = 1;

	while (running)
	{
		SDL_Event	event;

		while (SDL_PollEvent(&event))
		{
			switch(event.type){
				case SDL_QUIT:	running = 0;
								_Exit(0);
				case SDL_KEYDOWN: switch(event.key.keysym.sym){
									case SDLK_ESCAPE:	running = 0;
														_Exit(0); }
				break;
			}
		}
		SDL_UpdateWindowSurface(wnd->w);

		// state = mfb_update(window, screen);
		// if (state == STATE_EXIT)
		// 	_Exit(0);
	}

	tpool_wait(render_pool);
	tpool_destroy(render_pool);
	free(Params);
	// if (state != STATE_EXIT || state == STATE_OK)
	// 	mfb_close(window);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
