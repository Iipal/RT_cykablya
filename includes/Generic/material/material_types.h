#ifndef MATERIAL_TYPES_H
# define MATERIAL_TYPES_H
# include "vector_types.h"

# ifndef E_MATERIAL
#  define E_MATERIAL

enum	e_material
{
	MATERIAL_START,
	NORMAL,
	COLOR,
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	EMITTER,
	MATERIAL_END
};

# endif

typedef t_v8sf	__attribute__((__aligned__(32)))	t_material_sf;
struct	__attribute__((__aligned__(32)))			s_material_sf;
union	__attribute__((__aligned__(32)))			u_material_sf;

#endif
