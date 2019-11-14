#ifndef CAMERA_TYPES_INTERNAL_H
# define CAMERA_TYPES_INTERNAL_H
# include "vector_types.h"
# include "camera_types.h"
# ifndef S_CAMERA_SF
#  define S_CAMERA_SF

struct		s_camera_sf
{
	t_v3sf	*restrict	lower_left_corner;
	t_v3sf	*restrict	horizontal;
	t_v3sf	*restrict	vertical;
	t_v3sf	*restrict	origin;
};

# endif

# ifndef S_ADVANCED_CAMERA_SF
#  define S_ADVANCED_CAMERA_SF

struct		s_advanced_camera_sf
{
	t_v3sf	lower_left_corner;
	t_v3sf	horizontal;
	t_v3sf	vertical;
	t_v3sf	origin;
	t_v3sf	u;
	t_v3sf	v;
	t_v3sf	w;
	t_v3sf	lens_radius;
} __attribute__((__aligned__(64)));

# endif

# ifndef S_CAMERA_DF
#  define S_CAMERA_DF
struct		s_camera_df
{
	t_v3df	*restrict	lower_left_corner;
	t_v3df	*restrict	horizontal;
	t_v3df	*restrict	vertical;
	t_v3df	*restrict	origin;
};

# endif

# ifndef E_CAMERA_PARAMS
#  define E_CAMERA_PARAMS

enum	e_camera_params
{
	FOV,
	ASPECT_RATIO,
	APERTURE,
	FOCUS_DISTANCE
};

# endif
#endif
