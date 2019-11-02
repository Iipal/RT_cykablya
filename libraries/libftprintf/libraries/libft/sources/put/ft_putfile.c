/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:21:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/05 16:07:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_putfile(char const *const file)
{
	int32_t const	fd = open(file, O_RDONLY);
	char			*temp;

	temp = NULL;
	if (0 > fd)
		return (false);
	while (0 < ft_gnl(fd, &temp))
	{
		ft_putendl(temp);
		ft_strdel(&temp);
	}
	close(fd);
	return (true);
}
