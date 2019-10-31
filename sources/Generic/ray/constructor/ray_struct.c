#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "ray_constructor.h"
#endif

struct s_ray_sf __attribute__((__overloadable__))
	*ray(void)
{
	struct s_ray_sf	*ptr;

	if (!(ptr = (__typeof__(ptr))valloc(sizeof(*ptr))))
		return (NULL);
	*ptr = __extension__((typeof(*ptr)){});
	return (ptr);
}

struct s_ray_sf __attribute__((__overloadable__))
	*ray(const float init)
{
	struct s_ray_sf	*ptr;

	(void)init;
	if (!(ptr = (__typeof__(ptr))valloc(sizeof(*ptr))))
		return (NULL);
	*ptr = __extension__((typeof(*ptr)){});
	return (ptr);
}

struct s_ray_df __attribute__((__overloadable__))
	*ray(const double init)
{
	struct s_ray_df	*ptr;

	(void)init;
	if (!(ptr = (__typeof__(ptr))valloc(sizeof(*ptr))))
		return (NULL);
	*ptr = __extension__((typeof(*ptr)){});
	return (ptr);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
