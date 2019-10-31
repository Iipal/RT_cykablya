/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_arr_to_v3sf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:54:37 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/31 19:22:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	sp_arr_to_v3sf(t_v3sf *const dst,
			JSON_Array const *const arr,
			char const *const param_name,
			size_t const obj_serial)
{
	int8_t	i;

	i = -1;
	NODO_F(arr, ERRIN_N(param_name, obj_serial + 1, "JSONArray", E_INVALID));
	IFDO_F(3 != json_array_get_count(arr),
		ERRIN_N(param_name, obj_serial + 1, "JSONArray elements", E_INVALID));
	while (3 > ++i)
	{
		IFDO_F(JSONNumber != json_value_get_type(json_array_get_value(arr, i)),
		ERRIN_N(param_name, obj_serial + 1, "JSONArray element", E_VEC_FMT));
		(*dst)[i] = json_array_get_number(arr, i);
	}
	return (true);
}
