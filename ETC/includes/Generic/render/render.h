#ifndef RENDER_H
# define RENDER_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include <stddef.h>
#  include "vector_types.h"
#  include "camera.h"
#  include "random_float.h"
#  include "hitable.h"
#  include "color_to_rgb.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

#  ifndef S_RENDER_PARAMS
#   define S_RENDER_PARAMS
struct s_render_params
{
	uint32_t	__attribute__((ALIGN))	*restrict	screen;
	size_t											screen_width;
	size_t											screen_height;
	ptrdiff_t										step;
	ptrdiff_t										start;
	ptrdiff_t										stop;
	union u_hitables	*restrict					hitables;
	size_t											samples;
	float											fov;
	char	__attribute__((__unused__))				stub[4];
} __attribute__((ALIGN));
#  endif

void __attribute__((ALIGN,ARCH))
render(struct s_render_params *restrict param);
void __attribute__((ALIGN,ARCH))
render_normal(struct s_render_params *restrict param);


#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
