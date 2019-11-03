/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:49:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/03 11:44:35 by tmaluh           ###   ########.fr       */
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
# include "parser_structs.h"
# include "vector_types.h"
# undef DECLARATION

t_scene	*scene_parser(char *file);

bool	sp_get_render_type(JSON_Object const *root, t_render *const render);
bool	sp_get_render_size(JSON_Object const *root,
			size_t *const w,
			size_t *const h);
bool	sp_get_render_camera(JSON_Object const *root,
			struct s_render_params *const dst);

bool	sp_get_object_material(JSON_Object const *mat,
			char const *mat_name,
			t_object *const obj,
			size_t const obj_serial);

typedef bool	(*t_fn_mats)(JSON_Object const*, t_object *const, size_t const);
bool	sp_object_mat_normal(JSON_Object const *mat,
			t_object *const obj,
			size_t const obj_serial);
bool	sp_object_mat_lambert(JSON_Object const *mat,
			t_object *const obj,
			size_t const obj_serial);
bool	sp_object_mat_metal(JSON_Object const *mat,
			t_object *const obj,
			size_t const obj_serial);
bool	sp_object_mat_dielect(JSON_Object const *mat,
			t_object *const obj,
			size_t const obj_serial);

bool	sp_get_objects(JSON_Object const *root, t_scene *const scene);

typedef bool	(*t_fn_objs)(JSON_Object const*,
					t_object *const,
					size_t const);
bool	sp_get_object_sphere(JSON_Object const *obj_json_sphere,
			t_object *const obj,
			size_t const obj_serial);

bool	sp_get_lights(JSON_Object const *root, t_scene *const scene);

bool	sp_get_v3sf_arr(t_v3sf *const dst,
			JSON_Array const *const arr,
			char const *const param_name,
			size_t const obj_serial);

void	*scene_free(t_scene *scene);

#endif
