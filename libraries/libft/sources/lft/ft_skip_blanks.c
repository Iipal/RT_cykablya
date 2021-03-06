/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_blanks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:42:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 09:55:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_skip_blanks(const char *restrict str)
{
	size_t	i;

	i = ~0UL;
	while (str[++i] && F_ISBLANK(str[i]))
		;
	return (i);
}
