/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:32:17 by coremart          #+#    #+#             */
/*   Updated: 2019/01/24 18:40:15 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <mlx.h>

int     key_press(int key, t_data *data)
{
    if (key == 53)
        exit(0);
    else if (key == 123)
    {
        data->points->x1 -= data->tab->zoom;
        data->points->x2 -= data->tab->zoom;
    }
    else if (key == 124)
    {
        data->points->x1 += data->tab->zoom;
        data->points->x2 += data->tab->zoom;
    }
    else if (key == 125)
    {
        data->points->y1 += data->tab->zoom;
        data->points->y2 += data->tab->zoom;
    }
    else if (key == 126)
    {
        data->points->y1 -= data->tab->zoom;
        data->points->y2 -= data->tab->zoom;
    }
    else
        return (0);
    mlx_destroy_image(data->mlx_ptr, data->img_info->img_ptr);
    data->img_info->img_ptr = mlx_new_image(data->mlx_ptr, LENGHT, HEIGHT);
    data->img_info->img_str = mlx_get_data_addr(data->img_info->img_ptr, &data->img_info->bpp, &data->img_info->len, &data->img_info->endian);
    draw(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_info->img_ptr, 0, 0);
    print_menu(data);
    return (0);
}
