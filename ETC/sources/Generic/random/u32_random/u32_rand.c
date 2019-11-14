#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "u32_rand.h"
#endif

uint32_t	u32_rand(void)
{
	static _Thread_local uint32_t	x = 123456789U;
	static _Thread_local uint32_t	y = 362436069U;
	static _Thread_local uint32_t	z = 521288629U;
	static _Thread_local uint32_t	w = 88675123U;
	const uint32_t					t = x ^ (x << 11U);

	x = y;
	y = z;
	z = w;
	return (w = w ^ (w >> 19U) ^ (t ^ (t >> 8U)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif

