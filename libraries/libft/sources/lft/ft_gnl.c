/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 12:31:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/24 15:50:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int32_t	catline_recursive(int32_t const fd, char **data,
								char **line, ssize_t nbytes)
{
	size_t	to_nl;
	char	*temp_nl;

	to_nl = ~0UL;
	while (data[fd][++to_nl] && '\n' != data[fd][to_nl])
		;
	if ('\n' == data[fd][to_nl])
	{
		*line = ft_strndup(data[fd], to_nl);
		temp_nl = ft_strdup(data[fd] + ++to_nl);
		free(data[fd]);
		data[fd] = temp_nl;
		if (!data[fd][0])
			ft_strdel(&data[fd]);
	}
	else if (!data[fd][to_nl])
	{
		if (BUFF_SIZE == nbytes)
			ft_gnl(fd, line);
		*line = ft_strdup(data[fd]);
		ft_strdel(&data[fd]);
	}
	return (1);
}

int8_t			ft_gnl(int32_t const fd, char **line)
{
	static char	*data[255];
	char		*temp;
	char		buff[BUFF_SIZE + 1];
	ssize_t		nbytes;

	if (0 > fd)
		return (-1);
	while (0 < (nbytes = read(fd, buff, BUFF_SIZE)))
	{
		buff[nbytes] = '\0';
		if (!data[fd])
			data[fd] = ft_strnew(0);
		temp = ft_strjoin(data[fd], buff);
		free(data[fd]);
		data[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (0 > nbytes)
		return (-1);
	if (!nbytes && (!data[fd] || !data[fd][0]))
		return (0);
	return (catline_recursive(fd, data, line, nbytes));
}