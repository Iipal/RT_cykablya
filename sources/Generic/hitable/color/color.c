#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "color.h"
#endif

static t_v3sf
	random_in_unit_sphere(void)
{
	t_v3sf					p;

	while	(1.0f <= length_squared(
		p = 2.0f * vec(random_float(), random_float(), random_float()) - 1.0f))
		;
	return (p);
}

#include <stddef.h>

static float __attribute__((__const__,__target__("avx,avx2")))
	schlick(register float cosine, register float ri)
{
	size_t					i;
	register float			r0;
	register float			pow_5;
	const register float	base = (1.0f - cosine);

	r0 = (1.0f - ri) / (1.0f + ri);
	r0 = r0 * r0;
	i = 4UL;
	pow_5 = (1.0f - cosine);
	while (i--)
		pow_5 *= base;
	return (r0 + (1.0f - r0) * pow_5);
}



# include "vector.h"
# include "material.h"
# include "vector_int_types.h"
# include "record_types_internal.h"

# include "random_float.h"

#include <assert.h>


static t_v3sf __attribute__((__overloadable__,__target__("avx,avx2")))
	scatter_labmbertian(
		register const union u_hitables *const restrict hitables,
		register const t_v3sf point,
		register const t_v3sf normal,
		register const t_v3sf attenuation,
		register const size_t depth)
{
		if (depth < 128.0f)
		{
			const t_v3sf	target = point + normal + random_in_unit_sphere();
			const t_ray_sf	scattered = ray(point, target - point);

			return (attenuation * color(scattered, hitables, depth + 1UL));
		}
		else
			return (vec(0.0f, 0.0f, 0.0f));
}

static t_v3sf __attribute__((__overloadable__,__target__("avx,avx2")))
	scatter_metal(
		register const union u_hitables *const restrict hitables,
		register const t_record_sf record,
		register const t_ray_sf r,
		register const size_t depth)
{
	if (depth < 128.0f)
	{
		t_v3sf			reflected;
		t_ray_sf		scattered;

		reflected = reflect(normalize(direction(r)), normal(record));
		scattered = ray(point(record), reflected
		+ fuzz(*(hitables[iter(record)].sphere.material))
		* random_in_unit_sphere());
		if (dot(direction(scattered), normal(record)) > 0.0f)
			return (albedo(*(hitables[iter(record)].sphere.material))
					* color(scattered, hitables, depth + 1UL));
		else
			return (albedo(*(hitables[iter(record)].sphere.material)));
	}
	else
		return (vec(0.0f, 0.0f, 0.0f));
}


t_v3sf __attribute__((__overloadable__,__target__("avx,avx2")))
	color(register const t_ray_sf r,
		register const union u_hitables *const restrict hitables,
		register const size_t depth)
{
	register const t_record_sf	record = hit(hitables, r, 0.001f, __FLT_MAX__);
	const size_t				i = ((t_record_mask_hi)record)[1];

	if (condition(record) && (material(record) == LAMBERTIAN))
		return (scatter_labmbertian(hitables, point(record), normal(record),
			albedo(*(hitables[iter(record)].sphere.material)), depth));
	else if (condition(record) && (material(record) == METAL))
		return (scatter_metal(hitables, record, r, depth));
	else if (condition(record) && (material(record) == DIELECTRIC))
	{
		if (depth < 128.0f)
		{
			register t_ray_sf	scattered;
			float				refracted;

			if (dot(direction(r), normal(record)) > 0.0f)
			{
				refracted = refract_cond(normalize(direction(r)), -normal(record), ri(*(hitables[i].sphere.material)));
				if (refracted >= 0.0f)
					scattered = (random_float() < schlick(ri(*(hitables[i].sphere.material)) * dot(direction(r), normal(record)) / length(direction(r)), ri(*(hitables[i].sphere.material))))
					? ray(point(record), reflect(normalize(direction(r)), normal(record)))
					: ray(point(record), refract_do(normalize(direction(r)), -normal(record), ri(*(hitables[i].sphere.material)), refracted));
				else
					scattered = (random_float() < 1.0f)
					? ray(point(record), reflect(normalize(direction(r)), normal(record)))
					: ray(point(record), refract_do(normalize(direction(r)), -normal(record), ri(*(hitables[i].sphere.material)), refracted));
				return ((albedo(*(hitables[iter(record)].sphere.material)))
						* color(scattered, hitables, depth + 1UL));
			}
			else
			{
				refracted = refract_cond(normalize(direction(r)), normal(record), (1.0f / ri(*(hitables[i].sphere.material))));
				if (refracted >= 0.0f)
					scattered = (random_float() < schlick(-dot(direction(r), normal(record)) / length(direction(r)), ri(*(hitables[i].sphere.material))))
					? ray(point(record), reflect(normalize(direction(r)), normal(record)))
					: ray(point(record), refract_do(normalize(direction(r)), normal(record), (1.0f / ri(*(hitables[i].sphere.material))), refracted));
				else
					scattered = (random_float() < 1.0f)
					? ray(point(record), reflect(normalize(direction(r)), normal(record)))
					: ray(point(record), refract_do(normalize(direction(r)), normal(record), (1.0f / ri(*(hitables[i].sphere.material))), refracted));
				return ((albedo(*(hitables[iter(record)].sphere.material)))
						* color(scattered, hitables, depth + 1UL));
			}
		}
		else
			return (vec(0.0f, 0.0f, 0.0f));
	}

	// if (condition && (material == DIELECTRIC))
	// {
	// 	if (depth < max_depth)
	// 	{
	// 		const t_v3sf	point = { record[2], record[3], record[4] };
	// 		const t_v3sf	normal = { record[5], record[6], record[7] };
	// 		const t_v3sf	reflected = reflect(normalize(direction(r)), normal);
	// 		const t_v3sf	attenuation = albedo(*(hitables[i].sphere.material));

	// 		register t_ray_sf	scattered;

	// 		if (dot(direction(r), normal) > 0.0f)
	// 			scattered = ray(point, refract_reflect(normalize(direction(r)),
	// 			-normal, ri(*(hitables[i].sphere.material)), reflected));
	// 		else
	// 			scattered = ray(point, refract_reflect(normalize(direction(r)),
	// 			normal, 1.0f / ri(*(hitables[i].sphere.material)), reflected));
	// 		return (attenuation * color(scattered, hitables, depth + 1UL));
	// 	}
	// 	else
	// 		return (vec(0.0f, 0.0f, 0.0f));
	// }
	else
	{
		const t_v3sf			factor = (normalize(direction(r)).y + 1.0f) * 0.5f;

		return (vec(1.0f, 1.0f, 1.0f) - factor + vec(0.5f, 0.7f, 1.0f) * factor);
	}
}


t_v3sf __attribute__((__overloadable__,__target__("avx,avx2")))
	color(register const t_ray_sf r,
		register const union u_hitables *const restrict hitables)
{
	register const t_record_sf	record = hit(hitables, r, 0.0f, __FLT_MAX__);
	const t_v3sf				normal_direction = normalize(direction(r));
	const t_v3sf				factor = (normal_direction.y + 1.0f) * 0.5f;
	const _Bool					condition = ((t_record_mask_qi)record)[0];

	if (condition)
		return (0.5f * (1.0f + vec(record[5], record[6], record[7])));
	else
		return (vec(1.0f, 1.0f, 1.0f) - factor + vec(0.5f, 0.7f, 1.0f) * factor);
}


#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
