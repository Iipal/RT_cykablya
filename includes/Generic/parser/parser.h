/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:49:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 20:47:34 by tmaluh           ###   ########.fr       */
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

# include "attributes.h"

# include "parser_params.h"
# include "parser_errno.h"

# include "parson.h"
# include "ft_printf.h"
# include "libft.h"

# define DECLARATION
# include "sphere_constructor.h"
# include "material_constructor.h"
# include "hitable_types.h"
# include "material.h"
# include "render.h"
# undef DECLARATION

# define IMPLEMETNATION
# include "hitable_types_internal.h"
# undef IMPLEMETNATION

typedef void	(*t_fnptr_render)(struct s_render_params *restrict);

typedef struct	s_render
{
	t_fnptr_render	fn;
	size_t			w;
	size_t			h;
	size_t			samples;
}				t_render;

typedef struct	s_scene
{
	t_render					render;
	struct s_render_params		cam;
	union u_hitables *restrict	objs;
}				t_scene;

t_scene __attribute__((ALIGN,ARCH))
*scene_parser(char *file);

bool __attribute__((ALIGN,ARCH))
sp_get_render_type(const JSON_Object *root, t_render *const render);

bool __attribute__((ALIGN,ARCH))
sp_get_render_camera(const JSON_Object *root,
					struct s_render_params *const dst);

t_material_sf __attribute__((ALIGN,ARCH))
*sp_get_object_material(const JSON_Object *obj_json,
						union u_hitables *restrict obj,
						size_t obj_serial);

typedef t_material_sf	*(*t_fn_mats)(const JSON_Object*,
									union u_hitables *restrict,
									size_t);

t_material_sf __attribute__((ALIGN,ARCH))
*sp_object_mat_normal(const JSON_Object *mat,
					union u_hitables *restrict obj,
					size_t obj_serial);

t_material_sf __attribute__((ALIGN,ARCH))
*sp_object_mat_lambert(const JSON_Object *mat,
					union u_hitables *restrict obj,
					size_t obj_serial);

t_material_sf __attribute__((ALIGN,ARCH))
*sp_object_mat_metal(const JSON_Object *mat,
					union u_hitables *restrict obj,
					size_t obj_serial);

t_material_sf __attribute__((ALIGN,ARCH))
*sp_object_mat_dielect(const JSON_Object *mat,
						union u_hitables *restrict obj,
						size_t obj_serial);

bool __attribute__((ALIGN,ARCH))
sp_get_objects(const JSON_Object *root, t_scene *const scene);

typedef bool	(*t_fn_objs)(const JSON_Object*,
					union u_hitables *restrict,
					size_t);

bool __attribute__((ALIGN,ARCH))
sp_get_object_sphere(const JSON_Object *obj_json,
					union u_hitables *restrict obj,
					size_t obj_serial);
bool __attribute__((ALIGN,ARCH))
sp_get_object_cone(const JSON_Object *obj_json,
					union u_hitables *restrict obj,
					size_t obj_serial);
bool __attribute__((ALIGN,ARCH))
sp_get_object_plane(const JSON_Object *obj_json,
					union u_hitables *restrict obj,
					size_t obj_serial);
bool __attribute__((ALIGN,ARCH))
sp_get_object_triangle(const JSON_Object *obj_json,
					union u_hitables *restrict obj,
					size_t obj_serial);
bool __attribute__((ALIGN,ARCH))
sp_get_object_cyiinder(const JSON_Object *obj_json,
			union u_hitables *restrict obj,
			size_t obj_serial);

bool __attribute__((ALIGN,ARCH))
sp_get_lights(const JSON_Object *root, t_scene *const scene);

bool __attribute__((ALIGN,ARCH))
sp_get_v3sf_arr(t_v3sf *const dst,
			JSON_Array const *const arr,
			char const *const param_name,
			size_t obj_serial);

void __attribute__((ALIGN,ARCH))
*scene_free(t_scene *scene);

#endif
