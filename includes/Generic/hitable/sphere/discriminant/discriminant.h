/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminant.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:05:32 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:05:33 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISCRIMINANT_H
# define DISCRIMINANT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,ARCH))
discriminant(const float a,
			const float b,
			const t_v3sf oc,
			const t_v3sf radius);
double __attribute__((CONST,CLONE,ARCH))
discriminant(const double a,
			const double b,
			const t_v3df oc,
			const t_v3df radius);
t_v3sf __attribute__((CONST,CLONE,ARCH))
discriminant(const t_v3sf a,
			const t_v3sf b,
			const t_v3sf oc,
			const t_v3sf radius);
t_v3df __attribute__((CONST,CLONE,ARCH))
discriminant(const t_v3df a,
			const t_v3df b,
			const t_v3df oc,
			const t_v3df radius);

# endif
#endif
