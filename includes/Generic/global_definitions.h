/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_definitions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:59:58 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 21:59:59 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_DEFINITIONS_H
# define GLOBAL_DEFINITIONS_H
# ifndef M_PI
#  define M_PI (3.14159265358979323846)
# endif

# if !defined(true) && !defined(false) && !defined(E_BOOLEAN)
#  define E_BOOLEAN

enum	e_boolean
{
	false,
	true
} __attribute__((__flag_enum__));

# endif
#endif
