/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 02:03:52 by coremart          #+#    #+#             */
/*   Updated: 2019/01/26 02:03:53 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "mlx.h"

int			mouse_press(int button, int x, int y, t_mouse *mouse)
{
	(void)x;
	(void)y;
	if (button == 1)
		mouse->pressed = 1;
	return (0);
}

int			mouse_release(int button, int x, int y, t_mouse *mouse)
{
	(void)x;
	(void)y;
	(void)button;
	mouse->pressed = 0;
	return (0);
}


int			mouse_move(int x, int y, t_data *data)
{
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->pressed)
	{
		rot_matrix(data->tab, (float)(x - data->mouse->previous_x), (float)(y - data->mouse->previous_y));
        mlx_destroy_image(data->mlx_ptr, data->img_info->img_ptr);
        data->img_info->img_ptr = mlx_new_image(data->mlx_ptr, LENGHT, HEIGHT);
        data->img_info->img_str = mlx_get_data_addr(data->img_info->img_ptr, &data->img_info->bpp, &data->img_info->len, &data->img_info->endian);
        draw(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_info->img_ptr, 0, 0);
        print_menu(data);
	}
	return (0);
}