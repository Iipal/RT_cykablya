#ifndef GLOBAL_DEFINITIONS_H
# define GLOBAL_DEFINITIONS_H
# ifndef M_PI
#  define M_PI (3.14159265358979323846)
# endif

#  if !defined(true) && !defined(false) && !defined(E_BOOLEAN)
#   define E_BOOLEAN

enum	e_boolean
{
	false,
	true
} __attribute__((__flag_enum__));

#  endif
#endif
