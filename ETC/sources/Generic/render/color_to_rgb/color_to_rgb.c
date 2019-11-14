#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "color_to_rgb.h"
# include "vector.h"
#endif

static unsigned __attribute__((__target__("avx2"),__overloadable__))
	color_to_rgb(register const t_v3su col)
{
	register const t_v3su	shift_mask = { 16U, 8U, 0U };
	register const t_v3su	temp = col << shift_mask;

	return (temp[0] | temp[1] | temp[2]);
}

static t_v3sf __attribute__((__target__("avx,avx2"),__overloadable__))
	gamma_srgb(register const t_v3sf col)
{
	return vec(
		(col.x <= 0.0031308f)
		? 12.92f * col.x
		: 1.055f * __builtin_powf(col.x, (1.0f / 2.4f)) - 0.055f,
		(col.y <= 0.0031308f)
		? 12.92f * col.y
		: 1.055f * __builtin_powf(col.y, (1.0f / 2.4f)) - 0.055f,
		(col.z <= 0.0031308f)
		? 12.92f * col.z
		: 1.055f * __builtin_powf(col.z, (1.0f / 2.4f)) - 0.055f
	);
}

#include <assert.h>

static t_v3sf __attribute__((__target__("avx,avx2"),__overloadable__))
	gamma_rec2020(register const t_v3sf col)
{
	const float	alpha = 1.09929682680944f;
	const float	beta = 0.018053968510807f;

	return vec(
		(col.x < beta)
		? 4.500f * col.x
		: alpha * __builtin_powf(col.x, 0.45f) - (alpha - 1.0f),
		(col.y < beta)
		? 4.500f * col.y
		: alpha * __builtin_powf(col.y, 0.45f) - (alpha - 1.0f),
		(col.z < beta)
		? 4.500f * col.z
		: alpha * __builtin_powf(col.z, 0.45f) - (alpha - 1.0f)
	);
}

static t_v3sf __attribute__((__target__("avx,avx2"),__overloadable__))
	gamma_rec709(register const t_v3sf col)
{
	const float	alpha = 1.099f;
	const float	beta = 0.018f;

	return vec(
		(col.x < beta)
		? 4.500f * col.x
		: alpha * __builtin_powf(col.x, (1.0f / 2.4f)) - (alpha - 1.0f),
		(col.y < beta)
		? 4.500f * col.y
		: alpha * __builtin_powf(col.y, (1.0f / 2.4f)) - (alpha - 1.0f),
		(col.z < beta)
		? 4.500f * col.z
		: alpha * __builtin_powf(col.z, (1.0f / 2.4f)) - (alpha - 1.0f)
	);
}

unsigned __attribute__((__target__("avx,avx2"),__overloadable__))
	color_to_rgb(register const t_v3sf col)
{
	register const t_v3sf	color_shrink = { 255.9999999f, 255.9999999f, 255.9999999f };

	return color_to_rgb(__builtin_convertvector(
		gamma_rec2020(
			(col / (col + 1.0f))) * color_shrink, t_v3su));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
