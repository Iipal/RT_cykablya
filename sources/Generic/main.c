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
	if (!(s = scene_parser(*argv)))
		return (EXIT_FAILURE);

	const size_t				render_threads = 8UL;
	const size_t				render_tasks = render_threads << 2UL;
	const size_t				render_part =
		(s->render.w * s->render.h / render_tasks);
	uint32_t	*restrict		screen;
	struct Window	*restrict	window;
	UpdateState					state;
	struct s_tpool	*restrict	render_pool;
	static const float			fov = 15.0f;

	if (!(window = mfb_open_ex("BLYAD'", s->render.w, s->render.h, 1)))
		return (-1);
	if (!(screen = (__typeof__(screen))(valloc(sizeof(*screen) * s->render.w * s->render.h))))
		return (-1);

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
		Params[i].screen = screen;
		Params[i].look_from = s->cam.look_from;
		Params[i].look_at = s->cam.look_at;
		Params[i].position = s->cam.position;
		Params[i].fov = s->cam.fov;
		Params[i].aspect_ratio = (float)s->render.w / (float)s->render.h;
		Params[i].aperture = s->cam.aperture;
		Params[i].dist_to_focus = s->cam.dist_to_focus;
		tpool_add_work(render_pool, (void(*)(void*))s->render.fn,
			Params + i);
	}

//!!! Для рандомной сцены

	// const size_t					count = 100UL;
	// union u_hitables	*restrict	hitables;
	// if (!(hitables = scene_generator(count)))
	// 	return (-1);

	// for (size_t i = 0; i < render_tasks; i++)
	// {
	// 	Params[i].screen_width = s->render.w;
	// 	Params[i].screen_height = s->render.h;
	// 	Params[i].start = render_part * i;
	// 	Params[i].stop = render_part * (i + 1);
	// 	Params[i].step = 1UL;
	// 	Params[i].hitables = hitables;
	// 	Params[i].samples = s->render.samples;
	// 	Params[i].screen = screen;
	// 	Params[i].look_from = vec( 13.0f, 2.0f, 3.0f );//s->cam.look_from;
	// 	Params[i].look_at = s->cam.look_at;
	// 	Params[i].position = s->cam.position;
	// 	Params[i].fov = 20.0f;//s->cam.fov;
	// 	Params[i].aspect_ratio = (float)s->render.w / (float)s->render.h;
	// 	Params[i].aperture = 0.1f;//s->cam.aperture;
	// 	Params[i].dist_to_focus = 10.0f;//s->cam.dist_to_focus;
	// 	tpool_add_work(render_pool, (void(*)(void*))s->render.fn,
	// 		Params + i);
	// }

//!!!

	// tpool_wait(render_pool);








	while (-42)
	{

		// for (size_t current_samples = 2; current_samples < samples; current_samples += 1UL)
		// {
		// 	for (size_t i = 0; i < render_tasks; i++)
		// 	{
		// 		Params[i].s->render.w = s->render.w;
		// 		Params[i].s->render.h = s->render.h;
		// 		Params[i].start = render_part * i;
		// 		Params[i].stop = render_part * (i + 1);
		// 		Params[i].step = 1UL;
		// 		Params[i].hitables = hitables;
		// 		Params[i].samples = current_samples;
		// 		Params[i].screen = screen;
		// 		Params[i].fov = fov;
		// 		tpool_add_work(render_pool, (void(*)(void*))render_std, Params + i);
		// 		state = mfb_update(window, screen);
		// 		if (state != STATE_OK)
		// 			break ;
		// 	}
		// 	if (state != STATE_OK)
		// 		break ;
		// 	tpool_wait(render_pool);
		// }
		// tpool_destroy(render_pool);


		state = mfb_update(window, screen);
		if (state == STATE_EXIT)
			_Exit(0);
	}

	tpool_wait(render_pool);
	tpool_destroy(render_pool);
	free(screen);
	free(Params);
	if (state != STATE_EXIT || state == STATE_OK)
		mfb_close(window);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
