/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_vec_reduce_add.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:24:50 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:24:51 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_VEC_REDUCE_ADD_H
# define ASM_VEC_REDUCE_ADD_H

extern t_v2sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v2sf_reduce_add(register const t_v2sf vec);
extern t_v2df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v2df_reduce_add(register const t_v2df vec);
extern t_v3sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v3sf_reduce_add(register const t_v3sf vec);
extern t_v3df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v3df_reduce_add(register const t_v3df vec);
extern t_v4sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v4sf_reduce_add(register const t_v4sf vec);
extern t_v4df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v4df_reduce_add(register const t_v4df vec);

#endif
