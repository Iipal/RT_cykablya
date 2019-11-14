/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:49:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 18:02:07 by tmaluh           ###   ########.fr       */
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
# include "material_constructor.h"
# include "sphere_constructor.h"
# include "hitable_types.h"
# include "material.h"
# include "render.h"
# undef DECLARATION

# define IMPLEMETNATION
# include "hitable_types_internal.h"
# include "scene_generator/scene_generator.h"
# undef IMPLEMETNATION

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
};

/*
**	start parser:
*/
struct s_scene __attribute__((ALIGN,ARCH))
*scene_parser(const char *restrict file);

/*
**	getting render and camera settings:
*/
bool __attribute__((ALIGN,ARCH))
sp_get_render_type(const JSON_Object *restrict root,
	struct s_render *restrict render);
bool __attribute__((ALIGN,ARCH))
sp_get_render_camera(const JSON_Object *restrict root,
	struct s_render_params *restrict dst);

/*
**	getting random objects:
*/
union u_hitables __attribute__((ALIGN,ARCH))
*sp_get_random_objects(const JSON_Object *restrict root);

/*
**	getting objects:
*/
bool __attribute__((ALIGN,ARCH))
sp_get_objects(const JSON_Object *restrict root,
	struct s_scene *restrict scene);

typedef bool	(*t_fn_objs)(const JSON_Object *restrict,
					union u_hitables *restrict,
					const size_t);

bool __attribute__((ALIGN,ARCH))
sp_get_object_sphere(const JSON_Object *restrict obj_json,
	union u_hitables *restrict obj,
	const size_t obj_serial);
bool __attribute__((ALIGN,ARCH))
sp_get_object_cone(const JSON_Object *restrict obj_json,
	union u_hitables *restrict obj,
	const size_t obj_serial);
bool __attribute__((ALIGN,ARCH))
sp_get_object_plane(const JSON_Object *restrict obj_json,
	union u_hitables *restrict obj,
	const size_t obj_serial);
bool __attribute__((ALIGN,ARCH))
sp_get_object_triangle(const JSON_Object *restrict obj_json,
	union u_hitables *restrict obj,
	const size_t obj_serial);
bool __attribute__((ALIGN,ARCH))
sp_get_object_cyiinder(const JSON_Object *restrict obj_json,
	union u_hitables *restrict obj,
	const size_t obj_serial);

/*
**	getting object materials:
*/
t_material_sf __attribute__((ALIGN,ARCH))
*sp_get_object_material(const JSON_Object *restrict obj_json,
	union u_hitables *restrict obj,
	const size_t obj_serial);

typedef t_material_sf	*(*t_fn_mats)(const JSON_Object *restrict,
							const size_t);

t_material_sf __attribute__((ALIGN,ARCH))
*sp_object_mat_normal(const JSON_Object *restrict mat,
	const size_t obj_serial);
t_material_sf __attribute__((ALIGN,ARCH))
*sp_object_mat_lambert(const JSON_Object *restrict mat,
	const size_t obj_serial);
t_material_sf __attribute__((ALIGN,ARCH))
*sp_object_mat_metal(const JSON_Object *restrict mat,
	const size_t obj_serial);
t_material_sf __attribute__((ALIGN,ARCH))
*sp_object_mat_dielect(const JSON_Object *restrict mat,
	const size_t obj_serial);

/*
**	utils:
*/
bool __attribute__((ALIGN,ARCH))
spu_get_v3sf_arr(t_v3sf *restrict dst,
	const JSON_Array *restrict arr,
	const char *restrict param_name,
	const size_t obj_serial);

double __attribute__((ALIGN,ARCH))
spu_value_inrange(register double value,
	register double min_range,
	register double max_range);

/*
**	free:
*/
void __attribute__((ALIGN,ARCH))
*scene_free(struct s_scene *scene);

#endif
