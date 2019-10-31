// #if !defined(IMPLEMETNATION) && !defined(DECLARATION)
// # define IMPLEMETNATION
// # define DECLARATION
// // # include "aabb.h"
// #endif

// #  include <stddef.h>
// #  include "global_definitions.h"
// #  include "attributes.h"
// #  include "vector.h"
// #  include "ray.h"
// #  include "hitable.h"


// # ifndef U_SWAP_SF
// #  define U_SWAP_SF

// union	u_swap_sf
// {
// 	unsigned	u;
// 	float		f;
// } __attribute__((__transparent_union__));

// # endif



// extern inline void __attribute__((CLONE,ARCH,__gnu_inline__,__always_inline__))
// 	swap(union u_swap_sf *restrict a, union u_swap_sf *restrict b)
// {
// 	a->u ^= b->u ^= a->u ^= b->u;
// }
// void __attribute__((CLONE,ARCH,SMALL_STACK))
// 	swap(float *restrict a, float *restrict b)
// {
// 	return (swap((union u_swap_sf *restrict)a, (union u_swap_sf *restrict)b));
// }


// typedef float	__attribute__((__ext_vector_type__(6),__aligned__))	t_aabb_sf;

// float __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	ffmin(register const float a, register const float b)
// {
// 	return (a < b ? a : b);
// }
// double __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	ffmin(register const double a, register const double b)
// {
// 	return (a < b ? a : b);
// }


// float __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	ffmax(register const float a, register const float b)
// {
// 	return (a > b ? a : b);
// }
// double __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	ffmax(register const double a, register const double b)
// {
// 	return (a > b ? a : b);
// }


// t_aabb_sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	aabb(register const t_v3sf a, register const t_v3sf b)
// {
// 	t_aabb_sf	t;

// 	t.lo = a;
// 	t.hi = b;
// 	return (t);
// }
// t_aabb_sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	aabb(void)
// {
// 	return (__extension__((t_aabb_sf){}));
// }

// t_v3sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	min(register const t_aabb_sf aabb)
// {
// 	return (aabb.lo);
// }

// t_v3sf __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	max(register const t_aabb_sf aabb)
// {
// 	return (aabb.hi);
// }


// _Bool __attribute__((CONST,CLONE,ARCH,SMALL_STACK))
// 	hit(register const t_aabb_sf aabb,
// 		register const t_ray_sf ray,
// 		register const float t_min,
// 		register const float t_max)
// {
// 	size_t	i;
// 	float	inv_d;
// 	float	t_0;
// 	float	t_1;

// 	i = ~0UL;
// 	while (++i != 3)
// 	{
// 		inv_d = 1.0f / direction(ray)[i];
// 		t_0 = (min(aabb)[i] - origin(ray)[i]) * inv_d;
// 		t_1 = (max(aabb)[i] - origin(ray)[i]) * inv_d;
// 		if (inv_d < 0.0f)
// 			swap(&t_0, &t_1);
// 		if ((t_1 < t_max ? t_1 : t_max)
// 		<= ((t_0 > t_min ? t_0 : t_min)))
// 			return (false);
// 	}
// 	return (true);
// }


// t_aabb_sf __attribute__((CLONE,CONST,ARCH))
// 	bounding_box(register const t_sphere_sf sphere,
// 				register const float t_0,
// 				register const float t_1)
// {
// 	return (aabb(center(sphere) - radius(sphere),
// 				center(sphere) + radius(sphere)));
// }








// typedef float	__attribute__((__ext_vector_type__(6),ALIGN))	t_aabb_sf;

// typedef char	__attribute__((__ext_vector_type__(32),ALIGN))	t_v32qi;
// union	u_is_equal_helper
// {
// 	t_v32qi		vec;
// 	t_aabb_sf	param;
// } __attribute__((ALIGN));
// extern inline _Bool __attribute__((CLONE,ARCH,INLINE))
// 	is_equal(register const union u_is_equal_helper a,
// 			register const union u_is_equal_helper b)
// {
// 	return (0xffffff
// 	== (0xffffff & __builtin_ia32_pmovmskb256(a.vec == b.vec)));
// }
// _Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
// 	is_equal(register const t_aabb_sf a,
// 			register const t_aabb_sf b)
// {
// 	const union u_is_equal_helper	tmp_a = { .param = { a }};
// 	const union u_is_equal_helper	tmp_b = { .param = { b }};

// 	return (is_equal(tmp_a, tmp_b));
// }
// _Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
// 	is_equal(register const t_v32qi a,
// 			register const t_v32qi b)
// {
// 	const union u_is_equal_helper	tmp_a = { .vec = { a }};
// 	const union u_is_equal_helper	tmp_b = { .vec = { b }};

// 	return (is_equal(tmp_a, tmp_b));
// }


// extern inline _Bool __attribute__((CLONE,ARCH,INLINE))
// 	is_not_equal(register const union u_is_equal_helper a,
// 				register const union u_is_equal_helper b)
// {
// 	return (0xffffff
// 	!= (0xffffff & __builtin_ia32_pmovmskb256(a.vec == b.vec)));
// }
// _Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
// 	is_not_equal(register const t_aabb_sf a,
// 				register const t_aabb_sf b)
// {
// 	const union u_is_equal_helper	tmp_a = { .param = { a }};
// 	const union u_is_equal_helper	tmp_b = { .param = { b }};

// 	return (is_not_equal(tmp_a, tmp_b));
// }
// _Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
// 	is_not_equal(register const t_v32qi a,
// 				register const t_v32qi b)
// {
// 	const union u_is_equal_helper	tmp_a = { .vec = { a }};
// 	const union u_is_equal_helper	tmp_b = { .vec = { b }};

// 	return (is_not_equal(tmp_a, tmp_b));
// }


// extern inline _Bool __attribute__((CLONE,ARCH,INLINE))
// 	is_empty(register const union u_is_equal_helper a)
// {
// 	return (0 == (0xffffff & __builtin_ia32_pmovmskb256(a.vec)));
// }
// _Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
// 	is_empty(register const t_aabb_sf a)
// {
// 	const union u_is_equal_helper	tmp = { .param = { a }};

// 	return (is_empty(tmp));
// }
// _Bool __attribute__((CLONE,CONST,ARCH,SMALL_STACK))
// 	is_empty(register const t_v32qi a)
// {
// 	const union u_is_equal_helper	tmp = { .vec = { a }};

// 	return (is_empty(tmp));
// }









// t_aabb_sf __attribute__((CLONE,CONST,ARCH))
// 	surrounding_box(register const t_aabb_sf box_0,
// 					register const t_aabb_sf box_1)
// {
// 	return (aabb(
// 		vec(ffmin(min(box_0).x, min(box_1).x),
// 			ffmin(min(box_0).y, min(box_1).y),
// 			ffmin(min(box_0).z, min(box_1).z)),
// 		vec(ffmax(max(box_0).x, max(box_1).x),
// 			ffmax(max(box_0).y, max(box_1).y),
// 			ffmax(max(box_0).z, max(box_1).z))
// 	));
// }

// t_aabb_sf __attribute__((CLONE,CONST,ARCH))
// 	bounding_box(register const union u_hitables *const restrict hitables,
// 				register const float t_0,
// 				register const float t_1)
// {
	


// }


// bool hitable_list::bounding_box(float t0, float t1, aabb& box) const {
//     if (list_size < 1) return false;
//     aabb temp_box;
//     bool first_true = list[0]->bounding_box(t0, t1, temp_box);
//     if (!first_true)
//         return false;
//     else
//         box = temp_box;
//     for (int i = 1; i < list_size; i++) {
//         if(list[i]->bounding_box(t0, t1, temp_box)) {
//             box = surrounding_box(box, temp_box);
//         }
//         else
//             return false;
//     }
//     return true;
// }







// #if defined(IMPLEMETNATION) && defined(DECLARATION)
// # undef IMPLEMETNATION
// # undef DECLARATION
// #endif

