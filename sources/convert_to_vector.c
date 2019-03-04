/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:30:32 by coremart          #+#    #+#             */
/*   Updated: 2019/02/05 07:45:26 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <errno.h>

static void			find_mid(t_matrice *matrix, float *mid_x,
									float *mid_y, int *zoom)
{
	size_t y;

	y = 0;
	*mid_x = ((float)matrix->len - 1.0f) / 2.0f;
	while (matrix->next)
	{
		matrix = matrix->next;
		y++;
	}
	*zoom = ((LENGHT / (int)matrix->len < HEIGHT / (y + 1))
						? LENGHT / matrix->len : HEIGHT / (y + 1));
	*mid_y = (float)y / 2.0f;
}

static size_t		count_line(t_matrice *matrix)
{
	size_t i;

	i = 0;
	while (matrix)
	{
		matrix = matrix->next;
		i++;
	}
	return (i);
}

static t_vector_tab	*new_vector_tab(t_matrice *matrice,
								float *mid_x, float *mid_y)
{
	t_vector_tab *vector_tab;

	if (!(vector_tab = (t_vector_tab*)malloc(sizeof(t_vector_tab))))
		ft_error(errno);
	find_mid(matrice, mid_x, mid_y, &vector_tab->zoom);
	vector_tab->nb_lines = count_line(matrice);
	vector_tab->nb_col = matrice->len;
	if (!(vector_tab->tab = (t_vector**)malloc(sizeof(t_vector*)
											* vector_tab->nb_lines)))
		ft_error(errno);
	vector_tab->color = 0xFFFFFF;
	vector_tab->eigen.x = 0.0f;
	vector_tab->eigen.y = 0.0f;
	vector_tab->eigen.z = (float)vector_tab->zoom;
	return (vector_tab);
}

t_vector_tab		*convert_to_vector(t_matrice *matrix)
{
	float			mid_x;
	float			mid_y;
	size_t			j;
	int				i;
	t_vector_tab	*v_tab;

	v_tab = new_vector_tab(matrix, &mid_x, &mid_y);
	i = -1;
	while (++i < v_tab->nb_lines && (j = -1))
	{
		if (!(v_tab->tab[i] = (t_vector*)malloc(sizeof(t_vector)
													* matrix->len)))
			ft_error(errno);
		while (++j < matrix->len)
		{
			v_tab->tab[i][j].x = (float)v_tab->zoom * ((float)j - mid_x);
			v_tab->tab[i][j].y = (float)v_tab->zoom * ((float)i - mid_y);
			v_tab->tab[i][j].z = matrix->line[j] * v_tab->zoom;
			v_tab->tab[i][j].color = (matrix->line[j] > 0) ? 0xFFFFFF
															: 0x000000;
		}
		matrix = matrix->next;
	}
	return (v_tab);
}
