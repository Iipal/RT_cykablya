// #if !defined(IMPLEMETNATION) && !defined(DECLARATION)
// # define IMPLEMETNATION
// # define DECLARATION
// # include "material_constructor.h"
// #endif

// t_material_sf __attribute__((__target__("avx,avx2")))
// material(register const enum e_material material,
// 		register const t_v3sf albedo)
// {
// 	union u_material	ret;

// 	if ((material >= MATERIAL_END) || (material <= MATERIAL_START))
// 		return (__extension__((t_material_sf){}));
// 	ret.albedo = albedo;
// 	ret.vec_i[3] = (__typeof__(ret.vec_i[3]))(material);
// 	return (ret.vec);
// }


// bool scatter(
// 	const ray& r_in,
// 	const hit_record& rec,
//     vec3& attenuation,
//     ray& scattered)
// {
// 	vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
// 	scattered = ray(rec.p, reflected);
// 	attenuation = albedo;
// 	return (dot(scattered.direction(), rec.normal) > 0);
// }


// vec3 color(const ray& r, hitable *world, int depth) {
//     hit_record rec;
//     if (world->hit(r, 0.001, MAXFLOAT, rec)) {
//         ray scattered;
//         vec3 attenuation;
//         if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
//             return attenuation*color(scattered, world, depth+1);
//         }
//         else {
//             return vec3(0,0,0);
//         }
//     }
//     else {
//         vec3 unit_direction = unit_vector(r.direction());
//         float t = 0.5*(unit_direction.y() + 1.0);
//         return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
//     }
// }


// #if defined(IMPLEMETNATION) && defined(DECLARATION)
// # undef IMPLEMETNATION
// # undef DECLARATION
// #endif
