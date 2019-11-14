#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "lower_left_corner.h"
#endif

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(void)
{
	static _Thread_local t_v3sf	 coord = { -2.0f, -1.0f, -1.0f };

	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(register const float half_width,
						register const float half_height)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec(-half_width, -half_height, -1.0f);
	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*lower_left_corner(register const t_v3sf vec)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec;
	return (&coord);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
