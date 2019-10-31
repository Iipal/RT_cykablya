#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "rsqroot.h"
#endif

float __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
	rsqroot(register const float x)
{
	return (1.0f / asm_sqrtf(x));
}

double __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
	rsqroot(register const double x)
{
	return (1.0 / asm_sqrt(x));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
