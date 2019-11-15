/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:56:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 13:12:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DATA_H
# define PARSER_DATA_H

# include <stdbool.h>
# include "parson.h"

# define DECLARATION
# include "render.h"
# include "material.h"
# undef DECLARATION

# define IMPLEMETNATION
# include "hitable_types_internal.h"
# include "scene_generator/scene_generator.h"
# undef IMPLEMETNATION

typedef bool	(*t_fn_objs)(const JSON_Object *restrict,
					union u_hitables *restrict,
					const size_t);

typedef t_material_sf	*(*t_fn_mats)(const JSON_Object*restrict, const size_t);

typedef void	(*t_fnptr_render)(struct s_render_params *restrict);

struct	s_render
{
	t_fnptr_render	fn;
	size_t			w;
	size_t			h;
	size_t			samples;
};

struct	s_scene
{
	struct s_render				render;
	struct s_render_params		cam;
	union u_hitables *restrict	objs;
	bool						is_gi;
};

#endif
