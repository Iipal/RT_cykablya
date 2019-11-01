/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:49:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/01 12:14:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# include "parser_params.h"
# include "parser_errno.h"

# include "parson.h"
# include "ft_printf.h"
# include "libft.h"

# define DECLARATION
# include "render.h"
# include "vector_types.h"
# include "material.h"
# undef DECLARATION

typedef void	(*t_fnptr_render)(struct s_render_params*restrict);

typedef struct	s_scene
{
	size_t					screen_w;
	size_t					screen_h;
	t_fnptr_render			render_fn;
	struct s_render_params	cam;
	size_t					in_scene_objs;
}				t_scene;

t_scene	*scene_parser(char *file);

bool	sp_render_type(JSON_Object const *root, t_fnptr_render *fn);
bool	sp_screen_size(JSON_Object const *root, t_scene *const scene);
bool	sp_render_camera(struct s_render_params *const dst,
			JSON_Object const *root);

bool	sp_get_v3sf_arr(t_v3sf *const dst,
			JSON_Array const *const arr,
			char const *const param_name,
			size_t const obj_serial);

void	*scene_free(t_scene *scene);

#endif
