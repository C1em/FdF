/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:32:17 by coremart          #+#    #+#             */
/*   Updated: 2019/02/05 05:41:12 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <errno.h>

static void	add_to(t_vector *vec, t_param *arrow)
{
	if (arrow->axe == 'x')
	{
		vec->x += arrow->sign * 10;
		return ;
	}
	vec->y += arrow->sign * 10;
}

static void	key_arrow(int key, t_vector_tab *tab, t_param *arrow)
{
	if (key == 123 || key == 126)
		arrow->sign = -1;
	else
		arrow->sign = 1;
	if (key == 123 || key == 124)
		arrow->axe = 'x';
	foreach_vec(tab, &add_to, arrow);
}

static void	ft_zoom(t_vector *vec, int *key)
{
	if (*key == 69)
	{
		vec->x = vec->x * 1.10f;
		vec->y = vec->y * 1.10f;
		vec->z = vec->z * 1.10f;
		return ;
	}
	vec->x = vec->x * 100.0f / 110.0f;
	vec->y = vec->y * 100.0f / 110.0f;
	vec->z = vec->z * 100.0f / 110.0f;
}

static void	altitude(t_vector *vec, int *key)
{
	if (*key == 12)
		vec->z /= 1.2f;
	else
		vec->z *= 1.2f;
}

int			key_press(int key, t_data *data)
{
	t_param *param;

	if (!(param = (t_param*)malloc(sizeof(t_param))))
		ft_error(errno);
	param->zoom = &data->tab->zoom;
	if (key > 122 && key < 127)
		key_arrow(key, data->tab, param);
	else if (key == 69 || key == 78)
		foreach_vec(data->tab, &ft_zoom, &key);
	else if (key == 12 || key == 14)
		foreach_vec(data->tab, &altitude, &key);
	else if (key == 4)
		data->menu_open ^= 1;
	else if (key == 49)
		reset(data);
	else if (key > 81 && key < 86)
		ft_color(key, data->tab);
	else
		return (0);
	reset_img(data);
	free(param);
	return (0);
}
