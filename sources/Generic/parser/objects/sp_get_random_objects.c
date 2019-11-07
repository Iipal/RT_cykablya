/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_random_objects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:27:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 16:55:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

union u_hitables __attribute__((ALIGN,ARCH))
	*sp_get_random_objects(const JSON_Object *restrict root)
{
	const JSON_Value	*o = json_object_get_value(root, P_RANDOM);
	const JSON_Object	*o_obj = json_value_get_object(o);
	union u_hitables	*out;

	out = NULL;
	if (!o || !o_obj)
		return (out);
	NODO_R(json_object_has_value_of_type(o_obj, P_RCOUNT, JSONNumber),
		ERRIN_I(P_RANDOM, P_RCOUNT), out);
	out = scene_generator(spu_value_inrange(
		json_object_get_number(o_obj, P_RCOUNT), P_RCOUNT_MIN, P_O_MAX));
	return (out);
}
