#ifndef HITABLE_TYPES_H
# define HITABLE_TYPES_H

# ifndef E_HITABLES_TYPES
#  define E_HITABLES_TYPES

enum	e_hitables_types
{
	GENERIC,
	SPHERE,
	CONE,
	CYLINDER,
	PLANE,
	TETRAHEDRON
};

# endif

struct	s_generic;
struct	s_spheres;
struct	s_cones;
struct	s_cylinders;
struct	s_planes;
struct	s_tetrahedrons;
union	u_hitables;

#endif
