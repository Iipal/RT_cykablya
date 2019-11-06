/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:58:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/04 11:19:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void __attribute__((ALIGN,ARCH))
	*scene_free(t_scene *scene)
{

	if (scene)
	{
		FREE(scene->objs, free);
		FREE(scene, free);
	}
	return (NULL);
}
