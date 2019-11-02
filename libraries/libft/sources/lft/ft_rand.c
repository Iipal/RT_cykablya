/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 01:54:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 00:57:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_rand(size_t const limit)
{
	size_t			ponies;
	int32_t	const	fd = open("/dev/urandom", O_RDONLY);

	read(fd, &ponies, sizeof(size_t));
	close(fd);
	return (ponies % limit);
}
