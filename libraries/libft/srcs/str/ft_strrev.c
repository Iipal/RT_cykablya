/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:39:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 02:23:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *const str)
{
	size_t const	real_end = ft_strlen(str);
	size_t			start;
	size_t			end;

	start = ~0UL;
	end = real_end;
	while (real_end / 2L > ++start)
		SWAP(str[start], str[--end]);
}
