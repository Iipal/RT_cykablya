/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 11:23:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/03 22:35:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCTS_H
# define PARSER_STRUCTS_H

# define DECLARATION
# include "material.h"
# include "hitable_types_internal.h"
# include "render.h"
# undef DECLARATION

typedef void	(*t_fnptr_render)(struct s_render_params *restrict);

typedef struct	s_render
{
	t_fnptr_render	fn;
	size_t			w;
	size_t			h;
}				t_render;

typedef struct	s_scene
{
	t_render				render;
	struct s_render_params	cam;
	void *restrict			*objs;
	size_t					in_scene_objs;
}				t_scene;

#endif
