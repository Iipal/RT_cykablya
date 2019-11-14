#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "record.h"
#endif

t_record_sf __attribute__((CONST,CLONE,ARCH))
	record(register const float solution,
			register const t_v3sf point,
			register const t_v3sf center,
			register const t_v3sf radius)
{
	const t_v3sf		normal = (point - center) / radius;
	const int			val = 0x1;

	return (__extension__((t_record_sf){
		*(float*)&val,
		solution,
		point.x, point.y, point.z,
		normal.x, normal.y, normal.z
	}));
}

t_record_df __attribute__((CONST,CLONE,ARCH))
	record(register const double solution,
			register const t_v3df point,
			register const t_v3df center,
			register const t_v3df radius)
{
	const t_v3df		normal = (point - center) / radius;
	const long			val = 0x1;

	return (__extension__((t_record_df){
		*(double*)&val,
		solution,
		point.x, point.y, point.z,
		normal.x, normal.y, normal.z
	}));
}

t_record_sf __attribute__((CONST,CLONE,ARCH))
	record(register const t_record_sf current_record)
{
	static const t_record_mask_si	mask = { ~0 };

	return ((t_record_sf)((__typeof__(mask))(current_record) & ~mask));
}

t_record_df __attribute__((CONST,CLONE,ARCH))
	record(const t_record_df current_record)
{
	static const t_record_mask_di	mask = { ~0 };

	return ((t_record_df)((__typeof__(mask))(current_record) & ~mask));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
