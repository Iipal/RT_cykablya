#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sqroot.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const float val)
{
	return (asm_sqrtf(val));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const double val)
{
	return (asm_sqrt(val));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
