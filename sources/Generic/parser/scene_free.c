/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:58:02 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/07 09:52:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void __attribute__((ALIGN,ARCH))
	*scene_free(struct s_scene *scene)
{
	size_t			i;
	const size_t	max_objs = scene->objs->generic.count;

	i = ~0UL;
	if (scene)
	{
		while (max_objs > ++i)
		{
			FREE(scene->objs[i].generic.self, free);
			FREE(scene->objs[i].generic.material, free);
		}
		FREE(scene->objs, free);
		FREE(scene, free);
	}
	return (NULL);
}
