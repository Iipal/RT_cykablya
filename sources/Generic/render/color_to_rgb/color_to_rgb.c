#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "color_to_rgb.h"
#endif

static unsigned __attribute__((__target__("avx2"),__overloadable__))
	color_to_rgb(register const t_v3su col)
{
	register const t_v3su	shift_mask = { 16U, 8U, 0U };
	register const t_v3su	temp = col << shift_mask;

	return (temp[0] | temp[1] | temp[2]);
}

unsigned __attribute__((__target__("avx,avx2"),__overloadable__))
	color_to_rgb(register const t_v3sf col)
{
	register const t_v3sf	color_shrink = { 255.9999f, 255.9999f, 255.9999f };

	return color_to_rgb(__builtin_convertvector(col * color_shrink, t_v3su));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
