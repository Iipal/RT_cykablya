/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32_rand.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:25:59 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:26:00 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U32_RAND_H
# define U32_RAND_H

# ifdef IMPLEMETNATION
#  include <stdint.h>
#  include "attributes.h"
# endif

# ifdef DECLARATION

uint32_t __attribute__((ARCH,CLONE,ALIGN))
	u32_rand(void);

# endif
#endif
