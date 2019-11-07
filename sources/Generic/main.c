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
/* 	return (0);

	float	a = 5.0f;
	float	b = 3.0f;

	__builtin_printf("%.1f %.1f\n", a, b);

	swap(&a, &b);

	__builtin_printf("%.1f %.1f\n", a, b);

	return (0);

	float	res = 0.5f;
	int		iter = 100000;
	float	tst = (float)0x1ffffffff;
	// __builtin_printf("%.25f\n", 1.2345e-25f);
	// return (0);

	while (-42)
	{
		while (res >= 0.0f && res < 1.0f && !!iter)
		{
			res = random_float_tst(tst);
			iter--;
		}
		if (!(res >= 0.0f && res < 1.0f))
			break ;
		iter = 100000;
		tst -= 1.2345e-25f;
	}
	__builtin_printf("%.25f | %x\n", tst, *(unsigned*)&tst);
	return (0);

	while (-42) assert(random_float() < 1.0f && random_float() >= 0.0f);

	static const size_t			s->render.w = 4UL * 256UL;
	static const size_t			s->render.h = s->render.w / 2UL;
	static const size_t			samples = 100UL;
*/

	// static const size_t			s->render.w = 2560UL;
	// static const size_t			s->render.h = 1080UL;
	// static const size_t			samples = 64UL;

	t_plane_sf					planes[] = {
		plane(
			vec(0.1f, 0.0f, -0.1f),
			vec(0.0f, 0.1f, -0.1f),
			vec(0.0f, 0.0f, -0.3f),
			vec(0.2f, 0.0f, -0.5f)),
	};

	t_tetrahedron_sf			tetrahedrons[] = {
		tetrahedron(
			vec(0.1f, 0.0f, -0.1f),
			vec(0.0f, 0.1f, -0.1f),
			vec(0.0f, 0.0f, -0.3f)),
	};

	t_cone_sf					cones[] = {
		cone(vec(0.0f, -1.f, -1.0f), 0.5f, 1.6f),
		cone(vec(-1.0f, -1.0f, -1.0f), 0.5f, 1.6f),
		cone(vec(1.0f, -1.0f, -1.0f), 0.5f, 1.6f)
	};

	// t_cylinder_sf				cylinders[] = {
	// 	cylinder(vec(0.0f, -1.f, -1.0f), 0.5f, 2.0f),
	// 	cylinder(vec(-1.0f, -1.f, -1.0f), 0.5f, 2.0f),
	// 	cylinder(vec(1.0f, -1.f, -1.0f), 0.5f, 2.0f)
	// };

	t_cylinder_sf				cylinders[] = {
		cylinder(vec(0.0f, -1.0f, -1.0f), vec(0.2f, 2.0f, -1.0f), 0.5f),
		cylinder(vec(-1.0f, -1.0f, -1.0f), vec(-0.8f, 2.0f, -1.0f), 0.5f),
		cylinder(vec(1.0f, -1.0f, -1.0f), vec(1.0f, 2.0f, -1.5f), 0.5f)
	};

	t_sphere_sf					spheres[] = {
		sphere(vec(0.0f, 0.0f, -1.0f),		0.5f),
		sphere(vec(0.0f, -100.5f, -1.0f),	100.0f),
		sphere(vec(1.0f, 0.0f, -1.0f),		0.5f),
		sphere(vec(-1.0f, 0.0f, -1.0f),		0.5f),
		sphere(vec(-1.0f, 0.0f, -1.0f),		-0.45f)
	};

	t_material_sf				materials[] = {
		material(LAMBERTIAN,	vec(0.1f, 0.2f, 0.5f)),
		material(LAMBERTIAN,	vec(0.8f, 0.8f, 0.0f)),
		material(METAL,			vec(0.8f, 0.8f, 0.8f), 0.5f),
		material(DIELECTRIC,	1.5f)
	};

	// union u_hitables			hitables[] = {
	// 	(union u_hitables){ { GENERIC, 5, NULL, NULL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 1UL, materials + 1UL } },
	// 	(union u_hitables){ { CONE, 0, cones + 0UL, materials + 0UL } },
	// 	(union u_hitables){ { CONE, 0, cones + 1UL, materials + 2UL } },
	// 	(union u_hitables){ { CONE, 0, cones + 2UL, materials + 3UL } },
	// };

	// union u_hitables			hitables[] = {
	// 	(union u_hitables){ { GENERIC, 8, NULL, NULL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 0UL, materials + 0UL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 1UL, materials + 1UL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 2UL, materials + 2UL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 3UL, materials + 3UL } },
	// 	(union u_hitables){ { CONE, 0, cones + 0UL, materials + 0UL } },
	// 	(union u_hitables){ { CONE, 0, cones + 1UL, materials + 2UL } },
	// 	(union u_hitables){ { CONE, 0, cones + 2UL, materials + 3UL } },
	// };

	// union u_hitables			hitables[] = {
	// 	(union u_hitables){ { GENERIC, 5, NULL, NULL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 1UL, materials + 0UL } },
	// 	(union u_hitables){ { CYLINDER, 0, cylinders + 0UL, materials + 1UL } },
	// 	(union u_hitables){ { CYLINDER, 0, cylinders + 1UL, materials + 2UL } },
	// 	(union u_hitables){ { CYLINDER, 0, cylinders + 2UL, materials + 3UL } },
	// };



	// union u_hitables			hitables[] = {
	// 	(union u_hitables){ { GENERIC, 3, NULL, NULL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 1UL, materials + 0UL } },
	// 	(union u_hitables){ { TETRAHEDRON, 0, tetrahedrons + 0UL, materials + 1UL } },
	// };


	// union u_hitables			hitables[] = {
	// 	(union u_hitables){ { GENERIC, 3, NULL, NULL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 1UL, materials + 2UL } },
	// 	(union u_hitables){ { PLANE, 0, planes + 0UL, materials + 2UL } },
	// };


	// #ifndef M_PI_4
	// # define M_PI_4 (0.78539816339744830962f)
	// #endif

	// const float R = 1.0f;//__builtin_cosf(M_PI_4);

	// const t_material_sf			materials[] = {
	// 	material(LAMBERTIAN,	vec(0.0f, 0.0f, 1.0f)),
	// 	material(LAMBERTIAN,	vec(1.0f, 0.0f, 0.0f)),
	// };

	// const t_sphere_sf			spheres[] = {
	// 	sphere(vec(-R, 0.0f, -1.0f),		R),
	// 	sphere(vec( R, 0.0f, -1.0f),		R)
	// };

	const size_t				render_threads = 8UL;
	const size_t				render_tasks = render_threads << 2UL;
	const size_t				render_part =
		(s->render.w * s->render.h / render_tasks);

	uint32_t	*restrict		screen;
	struct Window	*restrict	window;

	UpdateState					state;

	struct s_tpool	*restrict	render_pool;

	static const float			fov = 15.0f;

	// union u_hitables	hitables[] = {
	// 	(union u_hitables){ { GENERIC, 3, NULL, NULL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 0UL, materials + 0UL } },
	// 	(union u_hitables){ { SPHERE, 0, spheres + 1UL, materials + 1UL } },
	// };

	// if (!(window = mfb_open_ex_buffer(&screen, "CYKA", s->render.w, s->render.h, WF_RESIZABLE)))
	// 	return (-1);
	if (!(window = mfb_open_ex("BLYAD'", s->render.w, s->render.h, 1)))
		return (-1);
	if (!(screen = (__typeof__(screen))(valloc(sizeof(*screen) * s->render.w * s->render.h))))
		return (-1);

	struct s_render_params	*restrict	Params = valloc((sizeof(*Params)) * render_tasks);
	render_pool = tpool_create(render_threads);

/* 	union u_hitables	*hitables;
	t_sphere_sf			*sp;
	t_material_sf		*mats;

	MEM(union u_hitables, hitables, 1UL + 4UL, E_ALLOC);
	MEM(t_sphere_sf, sp, 4UL, E_ALLOC);
	MEM(t_material_sf, mats, 4UL, E_ALLOC);

	*sp = sphere(vec(0.0f, 0.0f, -1.0f), 0.5f);
	*(sp + 1) = sphere(vec(0.0f, -100.5f, -1.0f), 100.0f);
	*(sp + 2) = sphere(vec(1.0f, 0.0f, -1.0f), 0.5f);
	*(sp + 3) = sphere(vec(-1.0f, 0.0f, -1.0f), 0.5f);
	*mats = material(LAMBERTIAN, vec(0.1f, 0.2f, 0.5f));
	*(mats + 1) = material(LAMBERTIAN, vec(0.8f, 0.8f, 0.0f));
	*(mats + 2) = material(METAL, vec(0.8f, 0.8f, 0.8f), 0.5f);
	*(mats + 3) = material(DIELECTRIC, 1.5f);
	*hitables = (union u_hitables) { GENERIC, 5UL, NULL, NULL };
	*(hitables + 1) = (union u_hitables) { SPHERE, 0, sp, mats };
	*(hitables + 2) = (union u_hitables) { SPHERE, 0, sp + 1UL, mats + 1UL };
	*(hitables + 3) = (union u_hitables) { SPHERE, 0, sp + 2UL, mats + 2UL };
	*(hitables + 4) = (union u_hitables) { SPHERE, 0, sp + 3UL, mats + 3UL }; */

	printf("\n\t**** | %zux%zu | ****\n", s->render.w, s->render.h);
	{
		char const *const	_current_render_type =
			(s->render.fn == render_std) ? "std"
				: (s->render.fn == render_full) ? "full"
					: (s->render.fn == render_normal) ? "normal"
						: "(null)";
		printf("\t++++ %s-render ++++\n\n", _current_render_type);
	}

	puts("Camera parameters: (x y z)");
	printf("\tlook_from: %f %f %f\n\tlook_at: %f %f %f\n\tpos: %f %f %f\n\n",
		s->cam.look_from[0], s->cam.look_from[1], s->cam.look_from[2],
		s->cam.look_at[0], s->cam.look_at[1], s->cam.look_at[2],
		s->cam.position[0], s->cam.position[1], s->cam.position[2]);

	printf("\tfov: %f\n\taperture: %f\n\tdist_to_focus: %f\n",
		s->cam.fov, s->cam.aperture, s->cam.dist_to_focus);

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
