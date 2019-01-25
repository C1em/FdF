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

static void add_to(char axe, int zoom, t_vector_tab *tab)
{
    int i;
    int j;

    i = 0;
    while (i < tab->nb_lines)
    {
        j = 0;
        while (j < tab->nb_col)
            if (axe == 'x')
                tab->tab[i][j++].x += zoom / 4;
            else
                tab->tab[i][j++].y += zoom / 4;
        i++;
    }
}

static void key_arrow(int key , t_vector_tab *tab)
{
    if (key == 123)
        add_to('x', -tab->zoom, tab);
    if (key == 124)
        add_to('x', tab->zoom, tab);
    if (key == 125)
        add_to('y', tab->zoom, tab);
    if (key == 126)
        add_to('y', -tab->zoom, tab);
}

int         key_press(int key, t_data *data)
{
    if (key == 53)
        exit(0);
    if (key > 122 && key < 127)
        key_arrow(key, data->tab);
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
