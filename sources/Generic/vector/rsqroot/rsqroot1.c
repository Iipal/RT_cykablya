#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "rsqroot.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const float x)
{
	return (1.0f / asm_sqrtf(x));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const double x)
{
	return (1.0 / asm_sqrt(x));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
