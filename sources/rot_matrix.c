/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:44:08 by coremart          #+#    #+#             */
/*   Updated: 2019/02/05 05:28:15 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include <math.h>
#include <errno.h>

static void	rot_vector(t_vector *vector, t_rot *rot)
{
	float x;
	float y;
	float z;

	x = vector->x;
	y = vector->y;
	z = vector->z;
	vector->x = x * (rot->vec->x * rot->vec->x * (1.0f - cos(rot->teta)) +
			cos(rot->teta)) + y * rot->vec->x * rot->vec->y *
			(1.0f - cos(rot->teta)) + z * rot->vec->y * sin(rot->teta);
	vector->y = x * rot->vec->x * rot->vec->y * (1.0f - cos(rot->teta)) +
			y * (rot->vec->y * rot->vec->y * (1.0f - cos(rot->teta))
			+ cos(rot->teta)) - z * rot->vec->x * sin(rot->teta);
	vector->z = -x * rot->vec->y * sin(rot->teta) + y *
			rot->vec->x * sin(rot->teta) + z * cos(rot->teta);
}

void		rot_matrix(t_vector_tab *tab, float x, float y)
{
	t_rot *rot;

	if (!(rot = (t_rot*)malloc(sizeof(t_rot))))
		ft_error(errno);
	if (!(rot->vec = (t_vector*)malloc(sizeof(t_vector))))
		ft_error(errno);
	rot->teta = sqrt(x * x + y * y) * 0.002f * ((y > 0) ? -1.0f : 1.0f);
	if (y == 0)
	{
		rot->teta = x * 0.002f;
		rot->vec->y = 1;
		rot->vec->x = 0;
	}
	else
	{
		rot->teta = sqrt(x * x + y * y) * 0.002f * ((y > 0) ? -1.0f : 1.0f);
		rot->vec->y = sin(atan(x / -y));
		rot->vec->x = cos(atan(x / -y));
	}
	foreach_vec(tab, &rot_vector, rot);
	rot_vector(&tab->eigen, rot);
	free(rot->vec);
	free(rot);
}
