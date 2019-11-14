#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "color_to_rgb.h"
#endif

static t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
	gamma_rec2020(register const t_v3sf col)
{
	const float	alpha = 1.09929682680944f;
	const float	beta = 0.018053968510807f;

	return vec(
		(col.x < beta)
		? 4.500f * col.x
		: alpha * sqroot(col.x) - (alpha - 1.0f),
		(col.y < beta)
		? 4.500f * col.y
		: alpha * sqroot(col.y) - (alpha - 1.0f),
		(col.z < beta)
		? 4.500f * col.z
		: alpha * sqroot(col.z) - (alpha - 1.0f)
	);
}

static unsigned __attribute__((CONST,SMALL_STACK,ARCH))
	color_to_rgb_helper(register const t_v3su col)
{
	register const t_v3su	shift_mask = { 16U, 8U, 0U };
	register const t_v3su	temp = col << shift_mask;

	return (temp[0] | temp[1] | temp[2]);
}

unsigned __attribute__((CONST,SMALL_STACK,ARCH))
	color_to_rgb(register const t_v3sf col)
{
	register const t_v3sf	color_shrink = { 255.99f, 255.99f, 255.99f };

	return color_to_rgb_helper(
		__builtin_convertvector(
			gamma_rec2020(
				(col / (col + 1.0f))
				) * color_shrink, t_v3su));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
