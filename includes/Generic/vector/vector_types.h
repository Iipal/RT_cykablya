/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:22:17 by sshevchu          #+#    #+#             */
/*   Updated: 2019/09/28 17:22:19 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TYPES_H
# define VECTOR_TYPES_H

# if defined(__GNUC__) && defined(__clang__)
#  ifndef T_V2SF
#   define T_V2SF

typedef float __attribute__((__ext_vector_type__(2),__aligned__(8)))	t_v2sf;

#  endif
#  ifndef T_V3SF
#   define T_V3SF

typedef float __attribute__((__ext_vector_type__(3),__aligned__))	t_v3sf;

#  endif
#  ifndef T_V4SF
#   define T_V4SF

typedef float __attribute__((__ext_vector_type__(4),__aligned__))	t_v4sf;

#  endif
#  ifndef T_V8SF
#   define T_V8SF

typedef float __attribute__((__ext_vector_type__(8),__aligned__))	t_v8sf;

#  endif
#  ifndef T_V2DF
#   define T_V2DF

typedef double __attribute__((__ext_vector_type__(2),__aligned__))	t_v2df;

#  endif
#  ifndef T_V3DF
#   define T_V3DF

typedef double __attribute__((__ext_vector_type__(3),__aligned__))	t_v3df;

#  endif
#  ifndef T_V4DF
#   define T_V4DF

typedef double __attribute__((__ext_vector_type__(4),__aligned__))	t_v4df;

#  endif
# elif defined(__GNUC__) && !defined(__clang__)
#  ifndef T_V2SF
#   define T_V2SF

typedef float __attribute__((__vector_size__(sizeof(float)*2UL)))	t_v2sf;

#  endif
#  ifndef T_V3SF
#   define T_V3SF

typedef float __attribute__((__vector_size__(sizeof(float)*4UL)))	t_v3sf;

#  endif
#  ifndef T_V4SF
#   define T_V4SF

typedef float __attribute__((__vector_size__(sizeof(float)*4UL)))	t_v4sf;

#  endif
#  ifndef T_V8SF
#   define T_V8SF

typedef float __attribute__((__vector_size__(sizeof(float)*8UL)))	t_v8sf;

#  endif
#  ifndef T_V2DF
#   define T_V2DF

typedef double __attribute__((__vector_size__(sizeof(double)*2UL)))	t_v2df;

#  endif
#  ifndef T_V3DF
#   define T_V3DF

typedef double __attribute__((__vector_size__(sizeof(double)*3UL)))	t_v3df;

#  endif
#  ifndef T_V4DF
#   define T_V4DF

typedef double __attribute__((__vector_size__(sizeof(double)*4UL)))	t_v4df;

#  endif
# else
#  ifndef T_V2SF
#   define T_V2SF

typedef float														t_v2sf[2];

#  endif
#  ifndef T_V3SF
#   define T_V3SF

typedef float														t_v3sf[3];

#  endif
#  ifndef T_V4SF
#   define T_V4SF

typedef float														t_v4sf[4];

#  endif
#  ifndef T_V8SF
#   define T_V8SF

typedef float														t_v8sf[8];

#  endif
#  ifndef T_V2DF
#   define T_V2DF

typedef double														t_v2df[2];

#  endif
#  ifndef T_V3DF
#   define T_V3DF

typedef double														t_v3df[3];

#  endif
#  ifndef T_V4DF
#   define T_V4DF

typedef double														t_v4df[4];

#  endif
# endif
#endif
