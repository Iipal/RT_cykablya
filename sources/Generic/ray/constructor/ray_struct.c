/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:46:42 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:46:44 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "ray_constructor.h"
#endif

struct s_ray_sf __attribute__((PURE,CLONE,ARCH))
	*ray(void)
{
	struct s_ray_sf	*ptr;

	if (!(ptr = (__typeof__(ptr))(valloc(sizeof(*ptr)))))
		return (NULL);
	*ptr = (struct s_ray_sf){ 0 };
	return (ptr);
}

struct s_ray_sf __attribute__((PURE,CLONE,ARCH))
	*ray(const float init)
{
	struct s_ray_sf	*ptr;

	(void)init;
	if (!(ptr = (__typeof__(ptr))(valloc(sizeof(*ptr)))))
		return (NULL);
	*ptr = (struct s_ray_sf){ 0 };
	return (ptr);
}

struct s_ray_df __attribute__((PURE,CLONE,ARCH))
	*ray(const double init)
{
	struct s_ray_df	*ptr;

	(void)init;
	if (!(ptr = (__typeof__(ptr))(valloc(sizeof(*ptr)))))
		return (NULL);
	*ptr = (struct s_ray_df){ 0 };
	return (ptr);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
