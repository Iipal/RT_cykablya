/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:07:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 11:43:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, char const c)
{
	size_t	len;

	len = ft_strlen(str);
	while (len && str[len] != c)
		--len;
	return ((c == str[len]) ? &str[len] : NULL);
}
