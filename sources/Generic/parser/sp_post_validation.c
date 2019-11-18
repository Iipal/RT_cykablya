/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_post_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:13:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/15 13:23:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Now only for validation cameara 'pos' param
*/

void __attribute__((ALIGN,ARCH))
	sp_post_validation(struct s_scene *restrict s)
{
	if (!s->cam.position[0] && !s->cam.position[1] && !s->cam.position[2])
		s->cam.position = (t_v3sf) { 0.0f, 1.0f, 0.0f };
}
