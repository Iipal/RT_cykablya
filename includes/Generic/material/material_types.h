/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:07:16 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:07:17 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_TYPES_H
# define MATERIAL_TYPES_H
# include "vector_types.h"

# ifndef E_MATERIAL
#  define E_MATERIAL

enum			e_material
{
	MATERIAL_START,
	NORMAL,
	COLOR,
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	EMITTER,
	MATERIAL_END
};

# endif

typedef t_v8sf	t_material_sf;
struct s_material_sf;
union u_material_sf;

#endif
