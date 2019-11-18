/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:58:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 13:10:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void __attribute__((ALIGN,ARCH))
	*scene_free(struct s_scene *scene)
{
	size_t	i;
	size_t	max_objs;

	i = ~0UL;
	if (scene)
	{
		if (scene->objs)
		{
			max_objs = scene->objs->generic.count;
			while (max_objs > ++i)
			{
				if ((void*)0x1 != scene->objs[i].generic.self)
					FREE(scene->objs[i].generic.self, free);
				FREE(scene->objs[i].generic.material, free);
			}
		}
		FREE(scene->objs, free);
		FREE(scene, free);
	}
	return (NULL);
}
