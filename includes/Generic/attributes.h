/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:59:45 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 21:59:46 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATTRIBUTES_H
# define ATTRIBUTES_H
# ifndef ARCH
#  define ARCH __target__("avx,avx2,fma")
# endif
# ifndef PURE
#  define PURE __pure__,__aligned__
# endif
# ifndef CONST
#  define CONST __const__,__aligned__
# endif
# ifndef CLONE
#  define CLONE __overloadable__
# endif
# ifndef SMALL_STACK
#  define SMALL_STACK __no_split_stack__
# endif
# ifndef ALIGN
#  define ALIGN __aligned__
# endif
# ifndef INLINE
#  define INLINE __always_inline__,__gnu_inline__
# endif
#endif
