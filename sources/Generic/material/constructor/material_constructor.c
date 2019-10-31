#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "material_constructor.h"
#endif

union	u_material_helper
{
	t_material_sf	sf;
	t_material_si	si;
} __attribute__((__aligned__(32)));

t_material_sf __attribute__((__target__("avx,avx2"),__overloadable__))
	material(register const enum e_material current_material,
			register const t_v3sf albedo)
{
	union	u_material_helper	ret;

	if ((current_material >= MATERIAL_END) || (current_material <= MATERIAL_START))
		return (__extension__((t_material_sf){}));
	ret.sf = __extension__((typeof(ret.sf)){ albedo[0], albedo[1], albedo[2] });
	ret.si[4] = (__typeof__(ret.si[4]))(current_material);
	return (ret.sf);
}

t_material_sf __attribute__((__target__("avx,avx2"),__overloadable__))
	material(register const enum e_material current_material,
			register const t_v3sf albedo,
			register const float fuzz)
{
	union	u_material_helper	ret;

	if (current_material != METAL)
		return (__extension__((t_material_sf){}));
	ret.sf = __extension__((typeof(ret.sf)){ albedo[0], albedo[1], albedo[2] });
	ret.si[4] = (__typeof__(ret.si[4]))(current_material);
	if (fuzz < 1.0f)
		ret.sf[5] = fuzz;
	else
		ret.sf[5] = 1.0f;
	return (ret.sf);
}

t_material_sf __attribute__((__target__("avx,avx2"),__overloadable__))
	material(register const enum e_material current_material,
			register const float ri)
{
	union	u_material_helper	ret;

	if (current_material != DIELECTRIC)
		return (__extension__((t_material_sf){}));
	ret.sf = __extension__((typeof(ret.sf)){ 1.0f, 1.0f, 1.0f });
	ret.si[4] = (__typeof__(ret.si[4]))(current_material);
	ret.sf[5] = ri;
	return (ret.sf);
}


#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
