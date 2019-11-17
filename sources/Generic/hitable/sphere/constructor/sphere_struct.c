/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:06:25 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:06:27 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sphere_constructor.h"
#endif

struct s_sphere_sf __attribute__((CLONE,ARCH))
	*sphere(void)
{
	struct s_sphere_sf	*s;

	if (!(s = (__typeof__(s))(valloc(sizeof(*s)))))
		return (NULL);
	*s = (struct s_sphere_sf){ 0 };
	return (s);
}

struct s_sphere_sf __attribute__((CLONE,ARCH))
	*sphere(const float f)
{
	struct s_sphere_sf	*s;

	(void)f;
	if (!(s = (__typeof__(s))(valloc(sizeof(*s)))))
		return (NULL);
	*s = (struct s_sphere_sf){ 0 };
	return (s);
}

struct s_sphere_df __attribute__((CLONE,ARCH))
	*sphere(const double f)
{
	struct s_sphere_df	*s;

	(void)f;
	if (!(s = (__typeof__(s))(valloc(sizeof(*s)))))
		return (NULL);
	*s = (struct s_sphere_df){ 0 };
	return (s);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
