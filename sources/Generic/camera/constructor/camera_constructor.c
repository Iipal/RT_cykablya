#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "camera_constructor.h"
#endif

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

struct s_advanced_camera_sf __attribute__((CLONE))
	*camera(register const t_v3sf look_from,
			register const t_v3sf look_at,
			register const t_v3sf position,
			register const t_v4sf params)
{
	struct s_advanced_camera_sf *restrict	ptr;
	float									half_height;
	float									half_width;

	half_height = __builtin_tanf(params[FOV] * (M_PI / 180.f) * 0.5f);
	half_width = params[ASPECT_RATIO] * half_height;
	if (!(ptr = (__typeof__(ptr))valloc(sizeof(*ptr))))
		return (NULL);
	ptr->lens_radius = params[APERTURE] / 2.0f;
	ptr->w = normalize(look_from - look_at);
	ptr->u = normalize(cross(position, ptr->w));
	ptr->v = cross(ptr->w, ptr->u);
	ptr->origin = look_from;
	ptr->lower_left_corner = ptr->origin
		- half_width * params[FOCUS_DISTANCE] * ptr->u
		- half_height * params[FOCUS_DISTANCE] * ptr->v
		- params[FOCUS_DISTANCE] * ptr->w;
	ptr->horizontal = 2.0f * params[FOCUS_DISTANCE] * half_width * ptr->u;
	ptr->vertical = 2.0f * params[FOCUS_DISTANCE] * half_height * ptr->v;
	return (ptr);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
