#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vertical.h"
#endif

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(void)
{
	static _Thread_local t_v3sf	 coord = { 0.0f, 2.0f, 0.0f };

	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(register const float half_height)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec(0.0f, 2.0f * half_height, 0.0f);
	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(register const t_v3sf vec)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec;
	return (&coord);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
