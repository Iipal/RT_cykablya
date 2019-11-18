/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_reduce_add.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:28:27 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:28:28 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_REDUCE_ADD_H
# define ASM_REDUCE_ADD_H

extern float __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v2sf(register const t_v2sf vec);
extern double __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v2df(register const t_v2df vec);
extern float __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v3sf(register const t_v3sf vec);
extern double __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v3df(register const t_v3df vec);
extern float __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v4sf(register const t_v4sf vec);
extern double __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v4df(register const t_v4df vec);

#endif
