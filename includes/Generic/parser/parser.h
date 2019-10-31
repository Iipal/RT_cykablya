/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:49:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/31 21:54:36 by tmaluh           ###   ########.fr       */
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

# include "parser_param_names.h"
# include "parser_errno.h"

# include "parson.h"
# include "ft_printf.h"
# include "libft.h"

# define DECLARATION
# include "render.h"
# include "vector_types.h"
# undef DECLARATION

typedef struct	s_scene
{
	size_t					in_scene_objs;
	struct s_render_params	*cam;
}				t_scene;

t_scene					*scene_parser(char *file);

struct s_render_params	*sp_render_camera(JSON_Object *root);

bool					sp_get_v3sf_arr(t_v3sf *const dst,
							JSON_Array const *const arr,
							char const *const param_name,
							size_t const obj_serial);

void	*scene_free(t_scene *scene);

#endif
