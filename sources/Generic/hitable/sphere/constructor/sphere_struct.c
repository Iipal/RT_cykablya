#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sphere_constructor.h"
#endif

struct s_sphere_sf __attribute__((CLONE,ARCH))
	*sphere(void)
{
	struct s_sphere_sf	*s;

	if (!(s = (__typeof__(s))(valloc(sizeof(*s)))))
		return (NULL);
	*s = (__extension__(typeof(*s)){});
	return (s);
}

struct s_sphere_sf __attribute__((CLONE,ARCH))
	*sphere(const float f)
{
	struct s_sphere_sf	*s;

	(void)f;
	if (!(s = (__typeof__(s))(valloc(sizeof(*s)))))
		return (NULL);
	*s = (__extension__(typeof(*s)){});
	return (s);
}

struct s_sphere_df __attribute__((CLONE,ARCH))
	*sphere(const double f)
{
	struct s_sphere_df	*s;

	(void)f;
	if (!(s = (__typeof__(s))(valloc(sizeof(*s)))))
		return (NULL);
	*s = (__extension__(typeof(*s)){});
	return (s);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
