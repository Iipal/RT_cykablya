/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_float.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:25:45 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:25:46 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_FLOAT_H
# define RANDOM_FLOAT_H

# ifdef IMPLEMETNATION
#  include "u32_rand.h"
# endif

# ifdef DECLARATION

float	random_float(void);

# endif
#endif
