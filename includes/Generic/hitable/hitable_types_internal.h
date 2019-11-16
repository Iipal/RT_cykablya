#ifndef HITABLE_TYPES_INTERNAL_H
# define HITABLE_TYPES_INTERNAL_H

# include <stddef.h>
# include "hitable_types.h"
# include "material_types.h"
# include "plane.h"
# include "sphere.h"
# include "cone.h"
# include "cylinder.h"
# include "tetrahedron.h"

# ifndef S_GENERIC
#  define S_GENERIC

struct  s_generic
{
	enum e_hitables_types	type;
	size_t					count : sizeof(int) * __CHAR_BIT__;
	void	*restrict		self;
	void	*restrict		material;
};

# endif
# ifndef S_SPHERES
#  define S_SPHERES

struct  s_spheres
{
	enum e_hitables_types		type;
	size_t						count : sizeof(int) * __CHAR_BIT__;
	t_sphere_sf		*restrict	self;
	t_material_sf	*restrict	material;
};

# endif
# ifndef S_CONES
#  define S_CONES

struct  s_cones
{
	enum e_hitables_types		type;
	size_t						count : sizeof(int) * __CHAR_BIT__;
	t_cone_sf		*restrict	self;
	t_material_sf	*restrict	material;
};

# endif
# ifndef S_CYLINDERS
#  define S_CYLINDERS

struct  s_cylinders
{
	enum e_hitables_types		type;
	size_t						count : sizeof(int) * __CHAR_BIT__;
	t_cylinder_sf	*restrict	self;
	t_material_sf	*restrict	material;
};

# endif
# ifndef S_TETRAHEDRONS
#  define S_TETRAHEDRONS

struct  s_tetrahedrons
{
	enum e_hitables_types			type;
	size_t							count : sizeof(int) * __CHAR_BIT__;
	t_tetrahedron_sf	*restrict	self;
	t_material_sf		*restrict	material;
};

# endif
# ifndef S_PLANES
#  define S_PLANES

struct  s_planes
{
	enum e_hitables_types		type;
	size_t						count : sizeof(int) * __CHAR_BIT__;
	t_plane_sf		*restrict	self;
	t_material_sf	*restrict	material;
};

# endif
# ifndef U_HITABLES
#  define U_HITABLES

union	u_hitables
{
	struct s_generic		generic;
	struct s_spheres		sphere;
	struct s_cones			cone;
	struct s_cylinders		cylinder;
	struct s_planes			plane;
	struct s_tetrahedrons	tetrahedron;
};

# endif
#endif
