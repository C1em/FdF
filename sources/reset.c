/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 05:37:35 by coremart          #+#    #+#             */
/*   Updated: 2019/02/05 06:02:40 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>

void	reset(t_data *data)
{
	free_tab(data->tab);
	data->tab = convert_to_vector(data->matrix);
}

void	reset_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_info->img_ptr);
	data->img_info->img_ptr = mlx_new_image(data->mlx_ptr, LENGHT, HEIGHT);
	data->img_info->img_str = mlx_get_data_addr(data->img_info->img_ptr,
		&data->img_info->bpp, &data->img_info->len, &data->img_info->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_info->img_ptr, 0, 0);
	print_menu(data);
}
