#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
// # include "aabb.h"
#endif

#  include <stddef.h>
#  include "global_definitions.h"
#  include "attributes.h"
#  include "vector.h"
#  include "ray.h"
#  include "hitable.h"


# ifndef U_SWAP_SF
#  define U_SWAP_SF

union	u_swap_sf
{
	unsigned	u;
	float		f;
} __attribute__((__transparent_union__));

# endif

# if !defined(E_BOOLEAN) && !defined(true) && !defined(false)
#  define E_BOOLEAN

enum	e_boolean
{
	false,
	true
} __attribute__((__flag_enum__));

# endif



extern inline void __attribute__((CLONE,ARCH,INLINE))
	swap(union u_swap_sf *restrict a, union u_swap_sf *restrict b)
{
	a->u ^= b->u ^= a->u ^= b->u;
}
void __attribute__((CLONE,ARCH,SMALL_STACK))
	swap(float *restrict a, float *restrict b)
{
	return (swap((union u_swap_sf *restrict)a, (union u_swap_sf *restrict)b));
}


float __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	ffmin(register const float a, register const float b)
{
	return (a < b ? a : b);
}
double __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	ffmin(register const double a, register const double b)
{
	return (a < b ? a : b);
}


float __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	ffmax(register const float a, register const float b)
{
	return (a > b ? a : b);
}
double __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	ffmax(register const double a, register const double b)
{
	return (a > b ? a : b);
}










typedef float	__attribute__((__ext_vector_type__(8),ALIGN))	t_aabb_sf;

typedef char	__attribute__((__ext_vector_type__(32),ALIGN))	t_v32qi;
union	u_is_equal_helper
{
	t_v32qi		vec;
	t_aabb_sf	param;
} __attribute__((ALIGN));
extern inline _Bool __attribute__((CLONE,ARCH,INLINE))
	is_equal(register const union u_is_equal_helper a,
			register const union u_is_equal_helper b)
{
	return (0x0fff0fff
	== (0x0fff0fff & __builtin_ia32_pmovmskb256(a.vec == b.vec)));
}
_Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
	is_equal(register const t_aabb_sf a,
			register const t_aabb_sf b)
{
	const union u_is_equal_helper	tmp_a = { .param = { a }};
	const union u_is_equal_helper	tmp_b = { .param = { b }};

	return (is_equal(tmp_a, tmp_b));
}
_Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
	is_equal(register const t_v32qi a,
			register const t_v32qi b)
{
	const union u_is_equal_helper	tmp_a = { .vec = { a }};
	const union u_is_equal_helper	tmp_b = { .vec = { b }};

	return (is_equal(tmp_a, tmp_b));
}


extern inline _Bool __attribute__((CLONE,ARCH,INLINE))
	is_not_equal(register const union u_is_equal_helper a,
				register const union u_is_equal_helper b)
{
	return (0x0fff0fff
	!= (0x0fff0fff & __builtin_ia32_pmovmskb256(a.vec == b.vec)));
}
_Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
	is_not_equal(register const t_aabb_sf a,
				register const t_aabb_sf b)
{
	const union u_is_equal_helper	tmp_a = { .param = { a }};
	const union u_is_equal_helper	tmp_b = { .param = { b }};

	return (is_not_equal(tmp_a, tmp_b));
}
_Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
	is_not_equal(register const t_v32qi a,
				register const t_v32qi b)
{
	const union u_is_equal_helper	tmp_a = { .vec = { a }};
	const union u_is_equal_helper	tmp_b = { .vec = { b }};

	return (is_not_equal(tmp_a, tmp_b));
}


extern inline _Bool __attribute__((CLONE,ARCH,INLINE))
	is_empty(register const union u_is_equal_helper a)
{
	return (0 == (0x0fff0fff & __builtin_ia32_pmovmskb256(a.vec)));
}
_Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
	is_empty(register const t_aabb_sf a)
{
	const union u_is_equal_helper	tmp = { .param = { a }};

	return (is_empty(tmp));
}
_Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
	is_empty(register const t_v32qi a)
{
	const union u_is_equal_helper	tmp = { .vec = { a }};

	return (is_empty(tmp));
}






t_aabb_sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	aabb(register const t_v3sf a, register const t_v3sf b)
{
	t_aabb_sf	t;

	t.lo.xyz = a;
	t.hi.xyz = b;
	return (t);
}
t_aabb_sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	aabb(void)
{
	return (__extension__((t_aabb_sf){}));
}

t_v3sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	min(register const t_aabb_sf aabb)
{
	return (aabb.lo.xyz);
}

t_v3sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	max(register const t_aabb_sf aabb)
{
	return (aabb.hi.xyz);
}

_Bool __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	condition_aabb(register const t_aabb_sf aabb)
{
	return (!!(aabb.lo.w));
}
t_aabb_sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	condition_aabb(register const t_aabb_sf aabb,
				register const _Bool set)
{
	t_aabb_sf	ret;

	ret = aabb;
	ret.lo.w = set;
	return (ret);
}
t_aabb_sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	not_bvh(register const t_aabb_sf aabb)
{
	t_aabb_sf	ret;

	ret = aabb;
	ret.lo.w = 0;
	return (ret);
}



t_aabb_sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
	hit(register const t_aabb_sf aabb,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max)
{
	size_t	i;
	float	inv_d;
	float	t_0;
	float	t_1;

	i = ~0UL;
	while (++i != 3)
	{
		inv_d = 1.0f / direction(ray)[i];
		t_0 = (min(aabb)[i] - origin(ray)[i]) * inv_d;
		t_1 = (max(aabb)[i] - origin(ray)[i]) * inv_d;
		if (inv_d < 0.0f)
			swap(&t_0, &t_1);
		if ((t_1 < t_max ? t_1 : t_max)
		<= ((t_0 > t_min ? t_0 : t_min)))
			return (not_bvh(aabb));
	}
	return (condition_aabb(aabb, true));
}












t_aabb_sf __attribute__((CLONE,CONST,ARCH))
	bounding_box(register const t_sphere_sf sphere,
				register const float t_0,
				register const float t_1)
{
	return (condition_aabb(
		aabb(center(sphere) - radius(sphere),
			center(sphere) + radius(sphere)), true));
}

t_aabb_sf __attribute__((CLONE,CONST,ARCH))
	surrounding_box(register const t_aabb_sf box_0,
					register const t_aabb_sf box_1)
{
	return (aabb(
		vec(ffmin(min(box_0).x, min(box_1).x),
			ffmin(min(box_0).y, min(box_1).y),
			ffmin(min(box_0).z, min(box_1).z)),
		vec(ffmax(max(box_0).x, max(box_1).x),
			ffmax(max(box_0).y, max(box_1).y),
			ffmax(max(box_0).z, max(box_1).z))
	));
}

t_aabb_sf __attribute__((CLONE,CONST,ARCH))
	bounding_box(register const union u_hitables *const restrict hitables,
				register const t_aabb_sf aabb,
				register const float t_0,
				register const float t_1)
{
	register t_aabb_sf	temp_box;
	register t_aabb_sf	current_box;
	size_t				i;

	current_box = aabb;
	if (hitables->generic.count < 1UL)
		return (condition_aabb(aabb, false));
	if (!condition_aabb(temp_box = bounding_box(*(hitables[1].sphere.self), t_0, t_1)))
		return (temp_box);
	else
		current_box = temp_box;
	i = 0UL;
	while (++i < hitables->generic.count)
		if (condition_aabb(temp_box = bounding_box(*(hitables[i].sphere.self), t_0, t_1)))
			current_box = surrounding_box(current_box, temp_box);
		else
			return (temp_box);
	return (current_box);
}

#include "hitable_types.h"
#include "hitable_types_internal.h"
#include "random_float.h"
#include <stdlib.h>

union	hitable_link
{
	union u_hitables	*restrict	hitables;
	struct s_bvh_node	*restrict	bvh_node;
}	__attribute__((ALIGN,__transparent_union__));

struct	s_bvh_node
{
	t_aabb_sf				box;
	union hitable_link		left;
	union hitable_link		right;
	enum e_hitables_types	left_type;
	enum e_hitables_types	right_type;
}	__attribute__((ALIGN));

// static int __attribute__((ARCH))
// 	box_x_compare(const void *a, const void *b)
// {
//     aabb box_left, box_right;
//     hitable *ah = *(hitable**)a;
//     hitable *bh = *(hitable**)b;

//     if (!ah->bounding_box(0,0, box_left) || !bh->bounding_box(0,0, box_right))
//         std::cerr << "no bounding box in bvh_node constructor\n";

//     if (box_left.min().x() - box_right.min().x() < 0.0)
//         return -1;
//     else
//         return 1;
// }

// static int __attribute__((ARCH))
// 	box_x_compare(const void *a, const void *b)
// {
//     aabb box_left, box_right;
//     hitable *ah = *(hitable**)a;
//     hitable *bh = *(hitable**)b;

//     if (!ah->bounding_box(0,0, box_left) || !bh->bounding_box(0,0, box_right))
//         std::cerr << "no bounding box in bvh_node constructor\n";

//     if (box_left.min().x() - box_right.min().x() < 0.0)
//         return -1;
//     else
//         return 1;
// }


// struct s_bvh_node __attribute__((ARCH))
// 	*bvh_node_constructor(
// 		register const union u_hitables *const restrict hitables,
// 		register const size_t n,
// 		register const float t_0,
// 		register const float t_1)
// {
// 	struct s_bvh_node	*restrict	new_node;
// 	const int						axis = (int)(3.0f * random_float());

// 	if (axis == 0)
// 		qsort(l, n, sizeof(hitable *), box_x_compare);



// }

// bvh_node::bvh_node(hitable **l, int n, float time0, float time1) {
//     int axis = int(3*drand48());
//     if (axis == 0)
//        qsort(l, n, sizeof(hitable *), box_x_compare);
//     else if (axis == 1)
//        qsort(l, n, sizeof(hitable *), box_y_compare);
//     else
//        qsort(l, n, sizeof(hitable *), box_z_compare);
//     if (n == 1) {
//         left = right = l[0];
//     }
//     else if (n == 2) {
//         left = l[0];
//         right = l[1];
//     }
//     else {
//         left = new bvh_node(l, n/2, time0, time1);
//         right = new bvh_node(l + n/2, n - n/2, time0, time1);
//     }
//     aabb box_left, box_right;
//     if (!left->bounding_box(time0,time1, box_left) ||
//         !right->bounding_box(time0,time1, box_right)
//        ) {
//         std::cerr << "no bounding box in bvh_node constructor\n";
//     }
//     box = surrounding_box(box_left, box_right);
// }





#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif

