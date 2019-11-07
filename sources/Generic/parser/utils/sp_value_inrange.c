/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_value_inrange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:46:33 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 13:15:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

double __attribute__((ALIGN,ARCH))
	sp_value_inrange(register double value,
		register double min_range,
		register double max_range)
{
	if (value > max_range)
		value = max_range;
	else if (value < min_range)
		value = min_range;
	return (value);
}
