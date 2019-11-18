/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_constructor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:18:38 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:18:41 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "material_constructor.h"
#endif

t_material_sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	material(register const enum e_material current_material,
			register const t_v3sf albedo)
{
	union u_material_helper	ret;

	if ((current_material >= MATERIAL_END)
	|| (current_material <= MATERIAL_START))
		return ((t_material_sf){ 0 });
	ret.sf = (t_material_sf){ albedo[0], albedo[1], albedo[2] };
	ret.si[4] = (__typeof__(ret.si[4]))(current_material);
	return (ret.sf);
}

t_material_sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	material(register const enum e_material current_material,
			register const t_v3sf albedo,
			register const float fuzz)
{
	union u_material_helper	ret;

	if (current_material != METAL)
		return ((t_material_sf){ 0 });
	ret.sf = (t_material_sf){ albedo[0], albedo[1], albedo[2]};
	ret.si[4] = (__typeof__(ret.si[4]))(current_material);
	if (fuzz < 1.0f)
		ret.sf[5] = fuzz;
	else
		ret.sf[5] = 1.0f;
	return (ret.sf);
}

t_material_sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	material(register const enum e_material current_material,
			register const float ri)
{
	union u_material_helper	ret;

	if (current_material != DIELECTRIC)
		return ((t_material_sf){ 0 });
	ret.sf = (t_material_sf){ 1.0f, 1.0f, 1.0f };
	ret.si[4] = (__typeof__(ret.si[4]))(current_material);
	ret.sf[5] = ri;
	return (ret.sf);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
