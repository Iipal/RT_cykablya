#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "record_point.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	point(register const t_record_sf record)
{
	return (vec(record[2], record[3], record[4]));
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	point(register const t_record_df record)
{
	return (vec(record[2], record[3], record[4]));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
