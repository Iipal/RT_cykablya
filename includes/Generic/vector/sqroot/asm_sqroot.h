/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_sqroot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:20:18 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:20:19 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_SQROOT_H
# define ASM_SQROOT_H

extern float __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_sqrtf(register const float val);
extern double __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_sqrt(register const double val);
extern t_v3sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v3sf_sqrtf(register const t_v3sf val);
extern t_v3df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v3df_sqrt(register const t_v3df val);
extern t_v4sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v4sf_sqrtf(register const t_v4sf val);
extern t_v4df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v4df_sqrt(register const t_v4df val);

#endif
