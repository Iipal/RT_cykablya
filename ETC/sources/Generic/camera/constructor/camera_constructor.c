#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "camera_constructor.h"
#endif

static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(void)
{
	static _Thread_local t_v3sf	 coord = { -2.0f, -1.0f, -1.0f };

	return (&coord);
}
static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(register const float half_width,
						register const float half_height)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec(-half_width, -half_height, -1.0f);
	return (&coord);
}
static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(register const t_v3sf vec)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec;
	return (&coord);
}



static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(void)
{
	static _Thread_local t_v3sf	 coord = { 4.0f, 0.0f, 0.0f };
	return (&coord);
}
static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(register const float half_width)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec(2.0f * half_width, 0.0f, 0.0f);
	return (&coord);
}
static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(register const t_v3sf vec)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec;
	return (&coord);
}



static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(void)
{
	static _Thread_local t_v3sf	 coord = { 0.0f, 2.0f, 0.0f };

	return (&coord);
}
static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(register const float half_height)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec(0.0f, 2.0f * half_height, 0.0f);
	return (&coord);
}
static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(register const t_v3sf vec)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec;
	return (&coord);
}



static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*origin(void)
{
	static _Thread_local t_v3sf	 coord = { 0.0f, 0.0f, 0.0f };

	return (&coord);
}
static t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*origin(register const t_v3sf vec)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec;
	return (&coord);
}



struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
	*camera(void)
{
	struct s_camera_sf	*ptr;

	if (!(ptr = (__typeof__(ptr))valloc(sizeof(*ptr))))
		return (NULL);
	*ptr = __extension__((typeof(*ptr)){
		lower_left_corner(),
		horizontal(),
		vertical(),
		origin() });
	return (ptr);
}

struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
	*camera(register const float fov,
			register const float aspect_ratio)
{
	const float			half_height	= __builtin_tanf(fov * (M_PI / 180.f) * 0.5f);
	const float			half_width	= aspect_ratio * half_height;
	struct s_camera_sf	*ptr;

	if (!(ptr = (__typeof__(ptr))valloc(sizeof(*ptr))))
		return (NULL);
	*ptr = __extension__((typeof(*ptr)){
		lower_left_corner(half_width, half_height),
		horizontal(half_width),
		vertical(half_height),
		origin() });
	return (ptr);
}

struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
	*camera(register const t_v3sf look_from,
			register const t_v3sf look_at,
			register const t_v3sf position,
			register const float fov,
			register const float aspect_ratio)
{
	const t_v3sf		w = normalize(look_from - look_at);
	const t_v3sf		u = normalize(cross(position, w));
	const float			half_height	= __builtin_tanf(fov * (M_PI / 180.f) * 0.5f);
	const float			half_width	= aspect_ratio * half_height;
	struct s_camera_sf	*ptr;

	if (!(ptr = (__typeof__(ptr))valloc(sizeof(*ptr))))
		return (NULL);
	*ptr = __extension__((typeof(*ptr)){
		lower_left_corner(look_from - half_width * u - half_height * cross(w, u) - w),
		horizontal(2.0f * half_width * u),
		vertical(2.0f * half_height * cross(w, u)),
		origin(look_from) });
	return (ptr);
}

#ifndef E_CAMERA_PARAMS
# define E_CAMERA_PARAMS

enum	e_camera_params
{
	FOV,
	ASPECT_RATIO,
	APERTURE,
	FOCUS_DISTANCE
};

#endif


static float __attribute__((ARCH,CONST,SMALL_STACK))
	fov(register const t_v4sf params)
{
	return (params[FOV]);
}

static float __attribute__((ARCH,CONST,SMALL_STACK))
	aspect_ratio(register const t_v4sf params)
{
	return (params[ASPECT_RATIO]);
}

static float __attribute__((ARCH,CONST,SMALL_STACK))
	aperture(register const t_v4sf params)
{
	return (params[APERTURE]);
}

static float __attribute__((ARCH,CONST,SMALL_STACK))
	focus_distance(register const t_v4sf params)
{
	return (params[FOCUS_DISTANCE]);
}



struct s_advanced_camera_sf __attribute__((__overloadable__))
	*camera(register const t_v3sf look_from,
			register const t_v3sf look_at,
			register const t_v3sf position,
			register const t_v4sf params)
{
	struct s_advanced_camera_sf *restrict	ptr;
	float									half_height;
	float									half_width;

	half_height = __builtin_tanf(fov(params) * (M_PI / 180.f) * 0.5f);
	half_width = aspect_ratio(params) * half_height;
	if (!(ptr = (__typeof__(ptr))valloc(sizeof(*ptr))))
		return (NULL);
	ptr->lens_radius = aperture(params) / 2.0f;
	ptr->w = normalize(look_from - look_at);
	ptr->u = normalize(cross(position, ptr->w));
	ptr->v = cross(ptr->w, ptr->u);
	ptr->origin = look_from;
	ptr->lower_left_corner = ptr->origin
		- half_width * focus_distance(params) * ptr->u
		- half_height * focus_distance(params) * ptr->v
		- focus_distance(params) * ptr->w;
	ptr->horizontal = 2.0f * focus_distance(params) * half_width * ptr->u;
	ptr->vertical = 2.0f * focus_distance(params) * half_height * ptr->v;
	return (ptr);
}




#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
