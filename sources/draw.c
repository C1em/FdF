/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:31:05 by coremart          #+#    #+#             */
/*   Updated: 2019/01/24 18:40:27 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <mlx.h>

#include <stdio.h>

static void    put_pixel(int x, int y, int color, char *img_str)
{
    unsigned int pixel;

    if (x >= LENGHT || y >= HEIGHT || x < 0 || y < 0)
        return ;
    pixel = (y * LENGHT + x) * 4;
    img_str[pixel] = color;
    img_str[pixel + 1] = color >> 8;
    img_str[pixel + 2] = color >> 16;
}

static void    draw_line(t_points *points, int color, char *img_str)
{
    int x1;
    int x2;
    int y1;
    int y2;
    float gradient;
    int x;
    float interY;
    int steep;

    x1 = points->x1;
    x2 = points->x2;
    y1 = points->y1;
    y2 = points->y2;
    steep = ft_absolute(y2 - y1) > ft_absolute(x2 - x1);
    if (steep)
    {
        ft_memswap(&x1 , &y1, 4);
        ft_memswap(&x2 , &y2, 4);
    }
    if (x1 > x2)
    {
        ft_memswap(&x1 ,&x2, 4);
        ft_memswap(&y1 ,&y2, 4);
    }
    if (x2 != x1)
        gradient = (float)(y2 - y1) / (float)(x2 - x1);
    else
        gradient = 1;
    interY = y1;
    x = x1;
    if (steep)
    {
        while (x <= x2)
        {
            put_pixel((int)interY, x, (int)((float)(unsigned char)color * (1 - (interY - (int)interY)))
            | (((int)((float)(unsigned char)(color >> 8) * (1 - (interY - (int)interY)))) << 8)
            | (((int)((float)(unsigned char)(color >>16) * (1 - (interY - (int)interY)))) << 16), img_str);
            put_pixel((int)interY - 1, x, (int)((float)(unsigned char)color * (interY - (int)interY))
            | (((int)((float)(unsigned char)(color >> 8) * (interY - (int)interY))) << 8)
            | (((int)((float)(unsigned char)(color >>16) * (interY - (int)interY))) << 16), img_str);
            interY += gradient;
            x++;
        }
    }
    else
    {
        while (x <= x2)
        {
            put_pixel(x, (int)interY, (int)((float)(unsigned char)color * (1 - (interY - (int)interY)))
            | (((int)((float)(unsigned char)(color >> 8) * (1 - (interY - (int)interY)))) << 8)
            | (((int)((float)(unsigned char)(color >>16) * (1 - (interY - (int)interY)))) << 16), img_str);
            put_pixel(x, (int)interY - 1, (int)((float)(unsigned char)color * (interY - (int)interY))
            | (((int)((float)(unsigned char)(color >> 8) * (interY - (int)interY))) << 8)
            | (((int)((float)(unsigned char)(color >>16) * (interY - (int)interY))) << 16), img_str);
            interY += gradient;
            x++;
        }
    }

}

static void    add_points(t_vector_tab *tab, t_data *data, int i, int j)
{
    data->points->x1 = tab->tab[i][j].x + LENGHT / 2;
    data->points->y1 = tab->tab[i][j].y + HEIGHT / 2;
    if (j + 1 != tab->nb_col)
    {
        data->points->x2 = tab->tab[i][j + 1].x + LENGHT / 2;
        data->points->y2 = tab->tab[i][j + 1].y + HEIGHT /2;
        draw_line(data->points, 0xFFFFFF, data->img_info->img_str);
    }
    if (i + 1 != tab->nb_lines)
    {
        data->points->x2 = tab->tab[i + 1][j].x + LENGHT / 2;
        data->points->y2 = tab->tab[i + 1][j].y + HEIGHT / 2;
        draw_line(data->points, 0xFFFFFF, data->img_info->img_str);
    }
}

void    draw(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->tab->nb_lines)
    {
        j = 0;
        while (j < data->tab->nb_col)
            add_points(data->tab, data, i, j++);
        i++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_info->img_ptr, 0, 0);
    print_menu(data);
    mlx_hook(data->win_ptr, 2, 0, &key_press, data);
}
