#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "horizontal.h"
#endif

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(void)
{
	static _Thread_local t_v3sf	 coord = { 4.0f, 0.0f, 0.0f };

	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(register const float half_width)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec(2.0f * half_width, 0.0f, 0.0f);
	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(register const t_v3sf vec)
{
	static _Thread_local t_v3sf	 coord;

	coord = vec;
	return (&coord);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
