/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:16:40 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/17 00:16:42 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECORD_TYPES_H
# define RECORD_TYPES_H
# if !defined(RECORD_ATTR)
#  define RECORD_ATTR(n) __ext_vector_type__(n),__aligned__(32)
# endif
# ifndef T_RECORD_SF
#  define T_RECORD_SF

typedef float __attribute__((RECORD_ATTR(8)))			t_record_sf;

# endif
# ifndef T_RECORD_DF
#  define T_RECORD_DF

typedef double __attribute__((RECORD_ATTR(8)))			t_record_df;

# endif
# if defined(RECORD_ATTR)
#  undef RECORD_ATTR
# endif
#endif
