#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "random_float.h"
#endif

float random_float(void)
{
	const unsigned	rnd = u32_rand();

	return ((float)rnd / 5e9f);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif

