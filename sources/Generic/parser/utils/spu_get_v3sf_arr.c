/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spu_get_v3sf_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:58:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 16:58:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool __attribute__((ALIGN,ARCH))
	spu_get_v3sf_arr(t_v3sf *restrict dst,
		const JSON_Array *restrict arr,
		const char *restrict param_name,
		const size_t obj_serial)
{
	int8_t	i;

	i = -1;
	NODO_F(arr, ERRIN_N(param_name, obj_serial + 1, "JSONArray", E_INVALID));
	IFDO_F(3 != json_array_get_count(arr),
		ERRIN_N(param_name, obj_serial + 1, "JSONArray", E_INVALID));
	while (3 > ++i)
	{
		IFDO_F(JSONNumber != json_value_get_type(json_array_get_value(arr, i)),
		ERRIN_N(param_name, obj_serial + 1, "JSONArray element", E_VEC_FMT));
		(*dst)[i] = (float)json_array_get_number(arr, i);
	}
	return (true);
}
