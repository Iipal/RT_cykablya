#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "record_iter.h"
#endif

size_t __attribute__((CONST,CLONE,ARCH))
	iter(register const t_record_sf record)
{
	return ((size_t)(((t_record_mask_hi)record)[1]));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
