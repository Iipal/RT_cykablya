#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "record.h"
#endif

t_record_sf __attribute__((CONST,CLONE,ARCH))
	record(register const float solution,
			register const t_v3sf point,
			register const t_v3sf normal)
{
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
			register const t_v3df normal)
{
	const long			val = 0x1;

	return (__extension__((t_record_df){
		*(double*)&val,
		solution,
		point.x, point.y, point.z,
		normal.x, normal.y, normal.z
	}));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
