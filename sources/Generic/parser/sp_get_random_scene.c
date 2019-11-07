/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_random_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:27:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 11:37:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

union u_hitables __attribute__((ALIGN,ARCH))
	*sp_get_random_scene(const JSON_Object *restrict root)
{
	const JSON_Value	*o = json_object_get_value(root, P_RANDOM);
	const JSON_Object	*o_obj = json_value_get_object(o);
	union u_hitables	*out;

	out = NULL;
	if (!o || !o_obj)
		return (out);
	NO_R(json_object_has_value_of_type(o_obj, P_RAND_COUNT, JSONNumber), out);
	out = scene_generator(json_object_get_number(o_obj, P_RAND_COUNT));
	return (out);
}
