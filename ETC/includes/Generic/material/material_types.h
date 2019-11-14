#ifndef MATERIAL_TYPES_H
# define MATERIAL_TYPES_H
# include "vector_types.h"

# ifndef E_MATERIAL
#  define E_MATERIAL
enum	e_material
{
	MATERIAL_START = 0,
	NORMAL = 1 << 0,
	LAMBERTIAN = 1 << 1,
	METAL = 1 << 2,
	DIELECTRIC = 1 << 3,
	EMITER = 1 << 4,
	COLOR = 1 << 5,
	MATERIAL_END = COLOR << 1
};
# endif

// typedef float	__attribute__((__vector_size__(32),__aligned__(32)))	t_material_sf;
typedef t_v8sf	__attribute__((__aligned__(32)))	t_material_sf;
struct	__attribute__((__aligned__(32)))			s_material_sf;
union	__attribute__((__aligned__(32)))			u_material_sf;

#endif
