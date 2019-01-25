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

static void add_to(t_vector *vec, t_param *arrow)
{
    if (arrow->axe == 'x')
    {
        vec->x += arrow->sign_or_key * arrow->zoom;
        return ;
    }
    vec->y += arrow->sign_or_key * arrow->zoom;
}

static void key_arrow(int key , t_vector_tab *tab, t_param *arrow)
{
    
    if (key == 123 || key == 126)
        arrow->sign_or_key = -1;
    else
        arrow->sign_or_key = 1;
    if (key == 123 || key == 124)
        arrow->axe = 'x';
    foreach_vec(tab, &add_to, arrow);
}

static void ft_zoom(t_vector *vec, t_param *param)
{
    if (param->sign_or_key == 69)
        {
            vec->x = vec->x + (vec->x / 10);
            vec->y = vec->y + (vec->y / 10);
            vec->z = vec->z + (vec->z / 10);
            return ;
        }
        vec->x = vec->x - (vec->x / 10);
        vec->y = vec->y - (vec->y / 10);
        vec->z = vec->z - (vec->z / 10);
}

int         key_press(int key, t_data *data)
{
    t_param *param;

    if (!(param = (t_param*)malloc(sizeof (t_param))))
        return (0);
    param->zoom = data->tab->zoom;
    if (key == 53)
        exit(0);
    if (key > 122 && key < 127)
        key_arrow(key, data->tab, param);
    else if ((param->sign_or_key = key) == 69 || param->sign_or_key == 78)
        foreach_vec(data->tab, &ft_zoom, param);
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
