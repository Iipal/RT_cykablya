#ifndef STRTOF_H
# define STRTOF_H

#include "errno.h"

__attribute__((__optimize__("O0"),__flatten__))
float	o_strtof(char *restrict s, char **restrict endptr);

__attribute__((__optimize__("Ofast"),__flatten__))
float	O_strtof(char *restrict s, char **restrict endptr);

__attribute__((__optimize__("Ofast"),__flatten__))
float	ft_strtof(char *restrict s, char **restrict endptr);

#endif
