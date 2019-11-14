#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "scene_generator.h"
#endif

static union u_hitables __attribute__((ALIGN,ARCH))
	*scene_generator_alloc(register const size_t count)
{
	union u_hitables	*restrict	hitables;
	t_material_sf		*restrict	materials;
	t_sphere_sf			*restrict	spheres;
	ptrdiff_t						i;

	if (!(hitables = (__typeof__(hitables))
		(valloc((sizeof(*hitables) * count)))))
		return (NULL);
	if (!(materials = (__typeof__(materials))
		(valloc((sizeof(*materials) * count)))))
		return (NULL);
	if (!(spheres = (__typeof__(spheres))
		(valloc((sizeof(*spheres) * count)))))
		return (NULL);
	*hitables = __extension__(
		(typeof(*hitables)){{ GENERIC, count, spheres, materials }});
	i = 0L;
	while (++i < count)
		hitables[i] = __extension__(
		(typeof(*hitables)){{ SPHERE, 0, spheres + i, materials + i }});
	return ((union u_hitables*)hitables);
}

static void __attribute__((ALIGN,ARCH,__nonnull__(1)))
	spheres_generator(register t_sphere_sf *const restrict spheres,
					register const size_t count)
{
	t_v3sf		center;
	size_t		i;
	float		a;
	float		b;
	const float	limit = sqroot((float)count) / 2.0f;

	if (count < 5UL)
		return ;
	i = 1UL;
	spheres[i++] = sphere(vec(0.0f, -1000.0f, 0.0f), 1000.0f);
	a = -limit;
	while ((a < limit) && (i < (count - 4UL)))
	{
		b = -limit;
		while ((b < limit) && (i < (count - 4UL)))
		{
			center = vec(a + 0.9f * random_float(), 0.2f,
						b + 0.9f * random_float());
			if (length((center - vec(4.0f, 0.2f, 0.0f))) > 0.9f)
				spheres[i++] = sphere(center, 0.2f);
			b += 1.0f;
		}
		a += 1.0f;
	}
	spheres[i++] = sphere(vec(0.0f, 1.0f, 0.0f), 1.0f);
    spheres[i++] = sphere(vec(-4.0f, 1.0f, 0.0f), 1.0f);
    spheres[i++] = sphere(vec(4.0f, 1.0f, 0.0f), 1.0f);
}

static void __attribute__((ALIGN,ARCH,__nonnull__(1)))
	materials_generator(register t_material_sf *const restrict materials,
						register const size_t count)
{
	size_t		i;
	float		choose_mat;
	float		a;
	float		b;
	const float	limit = sqroot((float)count) / 2.0f;

	if (count < 5UL)
		return ;
	i = 1UL;
	materials[i++] = material(LAMBERTIAN, vec(0.5f, 0.5f, 0.5f));
	a = -limit;
	while ((a < limit) && (i < (count - 4UL)))
	{
		b = -limit;
		while ((b < limit) && (i < (count - 4UL)))
		{
			choose_mat = random_float();
			if (choose_mat < 0.33f)
				materials[i++] = material(LAMBERTIAN,
					vec(random_float() * random_float(),
						random_float() * random_float(),
						random_float() * random_float()));
			else if (choose_mat < 0.66f)
				materials[i++] = material(LAMBERTIAN,
					vec(0.5f * (1.0f + random_float()),
						0.5f * (1.0f + random_float()),
						0.5f * (1.0f + random_float())));
			else
				materials[i++] = material(DIELECTRIC, 1.5f);
			b += 1.0f;
		}
		a += 1.0f;
	}
	materials[i++] = material(DIELECTRIC, 1.5f);
    materials[i++] = material(LAMBERTIAN, vec(0.4f, 0.2f, 0.1f));
    materials[i++] = material(METAL, vec(0.7f, 0.6f, 0.5f), 0.0f);
}

union u_hitables __attribute__((ALIGN,ARCH))
	*scene_generator(register const size_t count)
{
	union u_hitables	*restrict	hitables;
	size_t							i;

	if (!(hitables = (__typeof__(hitables))(scene_generator_alloc(count))))
		return (NULL);
	spheres_generator(hitables[1].sphere.self, count);
	materials_generator(hitables[1].sphere.material, count);
	return ((union u_hitables*)hitables);
}


#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
