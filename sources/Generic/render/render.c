#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "render.h"
#endif

static t_v4sf __attribute__((ARCH,CONST,SMALL_STACK))
	pack_params(register const float fov,
				register const float aspect_ratio,
				register const float aperture,
				register const float focus_distance)
{
	return (vec(fov, aspect_ratio, aperture, focus_distance));
}

void __attribute__((ALIGN,ARCH))
	render_std(struct s_render_params *restrict param)
{
	struct s_camera_sf	*restrict	cam;
	t_v3sf							col;
	ptrdiff_t						i;
	size_t							sample;

	cam = camera(90.0f, param->aspect_ratio);
	i = param->start - param->step;
	while ((i += param->step) < param->stop)
	{
		col = vec(0.0f, 0.0f, 0.0f);
		sample = param->samples;
		while (--sample)
			col	+= color(ray(cam,
				(t_v3sf)(((float)(i % (__typeof__(i))(param->screen_width))
				+ random_float()) / param->screen_width),
				(t_v3sf)(1.0f
				- ((float)(i / (__typeof__(i))(param->screen_width))
				+ random_float()) / param->screen_height)), param->hitables,
				0UL);
		*(param->screen + i)
		= color_to_rgb(col / (float)(param->samples));
	}
	free(cam);
}

void __attribute__((ALIGN,ARCH))
	render_full(struct s_render_params *restrict param)
{
	struct s_advanced_camera_sf	*restrict	cam;
	t_v3sf									col;
	ptrdiff_t								i;
	size_t									sample;

	cam = camera(param->look_from, param->look_at, param->position,
		pack_params(param->fov, param->aspect_ratio, param->aperture,
			param->dist_to_focus));
	i = param->start - param->step;
	while ((i += param->step) < param->stop)
	{
		col = vec(0.0f, 0.0f, 0.0f);
		sample = param->samples;
		while (--sample)
			col	+= color(ray(cam,
				(((float)(i % (__typeof__(i))(param->screen_width))
				+ random_float()) / param->screen_width),
			(1.0f - ((float)(i / (__typeof__(i))(param->screen_width))
				+ random_float()) / param->screen_height)),
			param->hitables, 0UL);
		*(param->screen + i)
		= color_to_rgb(col / (float)(param->samples));
	}
	free(cam);
}

void __attribute__((ALIGN,ARCH))
	render_normal(struct s_render_params *restrict param)
{
	struct s_camera_sf	*restrict	cam;
	ptrdiff_t						i;

	cam = camera(90.0f, param->aspect_ratio);
	i = param->start - param->step;
	while ((i += param->step) < param->stop)
		*(param->screen + i) = color_to_rgb((color(ray(cam,
			(t_v3sf)(((float)(i % (__typeof__(i))(param->screen_width))
			+ random_float()) / param->screen_width),
			(t_v3sf)(1.0f - ((float)(i / (__typeof__(i))(param->screen_width))
			+ random_float()) / param->screen_height)), param->hitables)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
