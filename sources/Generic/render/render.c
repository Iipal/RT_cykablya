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
		= color_to_rgb(sqroot(col / (float)(param->samples)));
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
		= color_to_rgb(sqroot(col / (float)(param->samples)));
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
		*(param->screen + i) = color_to_rgb(sqroot(color(ray(cam,
			(t_v3sf)(((float)(i % (__typeof__(i))(param->screen_width))
			+ random_float()) / param->screen_width),
			(t_v3sf)(1.0f - ((float)(i / (__typeof__(i))(param->screen_width))
			+ random_float()) / param->screen_height)), param->hitables)));
}




/* ВСё и сразу На случай пожара */

// void __attribute__((ALIGN,ARCH))
// 	render(struct s_render_params *restrict param)
// {
// 	// struct s_advanced_camera_sf	*restrict	cam;
// 	struct s_camera_sf	*restrict	cam;
// 	t_v3sf							col;
// 	ptrdiff_t						i;
// 	size_t							sample;


// 	// const t_v3sf					look_from = { 13.0f, 2.0f, 3.0f };
// 	// const t_v3sf					look_at = { 0.0f, 0.0f, 0.0f };
// 	// const t_v3sf					position = { 0.0f, 1.0f, 0.0f };
// 	// const float						fov = 20.0f;
// 	// const float						aspect_ratio = (float)(param->screen_width) / (float)(param->screen_height);
// 	// const float						aperture = 0.1f;
// 	// const float						dist_to_focus = 10.0f;
// 	// cam = camera(look_from, look_at, position, pack_params(fov, aspect_ratio, aperture, dist_to_focus));

// 	// const t_v3sf					look_from = { 3.0f, 3.0f, 2.0f };
// 	// const t_v3sf					look_at = { 0.0f, 0.0f, -1.0f };
// 	// const t_v3sf					position = { 0.0f, 1.0f, 0.0f };
// 	// const float						fov = param->fov;
// 	// const float						aspect_ratio = (float)(param->screen_width) / (float)(param->screen_height);
// 	// const float						aperture = 2.0f;
// 	// const float						dist_to_focus = length(look_from - look_at);


// 	// cam = camera();
// 	cam = camera(90.0f, (float)(param->screen_width) / (float)(param->screen_height));
// 	// cam = camera(fov, aspect_ratio);
// 	// cam = camera(vec(-2.0f, 2.0f, 1.0f), vec(0.0f, 0.0f, -1.0f), vec(0.0f, 1.0f, 0.0f), fov, aspect_ratio);


// 	i = param->start - param->step;
// 	while ((i += param->step) < param->stop)
// 	{
// 		// const float 	u = ((float)(i % (__typeof__(i))(param->screen_width))) / param->screen_width;
// 		// const float 	v = 1.0f - ((float)(i / (__typeof__(i))(param->screen_width))) / param->screen_height;
// 		// const t_v3sf	col	= color(ray(cam, (t_v3sf)u, (t_v3sf)v), param->hitables, 0UL);
// 		// *(param->screen + i) = color_to_rgb(sqroot(col));


// 		col = vec(0.0f, 0.0f, 0.0f);
// 		sample = param->samples;
// 		while (--sample)
// 		{

// 			// const float x = ((float)(i % (__typeof__(i))(param->screen_width)) + random_float());
// 			// const float y = ((float)(i / (__typeof__(i))(param->screen_width)) + random_float());
//    //          const float u = (2.0f * (x + 0.5f) / (float)(param->screen_width) - 1.0f) * aspect_ratio * scale;
//    //          const float v = (1.0f - 2.0f * (y + 0.5f) / (float)(param->screen_height)) * scale;



// 			// const float 	u = (((float)(i % (__typeof__(i))(param->screen_width)) + random_float()) / param->screen_width) * aspect_ratio * scale;
// 			// const float 	v = (1.0f - ((float)(i / (__typeof__(i))(param->screen_width)) + random_float()) / param->screen_height) * scale;

// 			const float 	u = ((float)(i % (__typeof__(i))(param->screen_width)) + random_float()) / param->screen_width;
// 			const float 	v = 1.0f - ((float)(i / (__typeof__(i))(param->screen_width)) + random_float()) / param->screen_height;
// 			col	+= color(ray(cam, (t_v3sf)u, (t_v3sf)v), param->hitables, 0UL);
// 			// col	+= color(ray(cam, u, v), param->hitables, 0UL);
// 		}
// 		*(param->screen + i) = color_to_rgb(sqroot(col / (float)(param->samples)));
// 	}
// 	free(cam);
// }

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
