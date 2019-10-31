#ifndef MATERIAL_TYPES_H
# define MATERIAL_TYPES_H
# include "vector_types.h"

# ifndef E_MATERIAL
#  define E_MATERIAL
enum	e_material
{
	MATERIAL_START,
	NORMAL,
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	MATERIAL_END
};
# endif

// typedef float	__attribute__((__vector_size__(32),__aligned__(32)))	t_material_sf;
typedef t_v8sf	__attribute__((__aligned__(32)))	t_material_sf;
struct	__attribute__((__aligned__(32)))			s_material_sf;
union	__attribute__((__aligned__(32)))			u_material_sf;

#endif
