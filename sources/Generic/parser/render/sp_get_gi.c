/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_gi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:51:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 12:55:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool __attribute__((ALIGN,ARCH))
	sp_get_gi(const JSON_Object *restrict obj)
{
	bool	ret;

	ret = true;
	if (json_object_has_value_of_type(obj, P_GI, JSONBoolean))
		ret = json_object_get_boolean(obj, P_GI);
	return (ret);
}
