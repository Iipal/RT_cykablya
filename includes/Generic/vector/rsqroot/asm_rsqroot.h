/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_rsqroot.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:17:50 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:17:51 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_RSQROOT_H
# define ASM_RSQROOT_H

extern t_v2sf __attribute__((CONST,SMALL_STACK,ARCH))
asm_v2sf_rsqroot(register const t_v2sf vec);
extern t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
asm_v3sf_rsqroot(register const t_v3sf vec);
extern t_v4sf __attribute__((CONST,SMALL_STACK,ARCH))
asm_v4sf_rsqroot(register const t_v4sf vec);

#endif
