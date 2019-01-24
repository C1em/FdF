/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:31:05 by coremart          #+#    #+#             */
/*   Updated: 2019/01/24 15:31:08 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <mlx.h>


static void    put_pixel(int x, int y, int color, char **img_str)
{
    unsigned int pixel;
    
    if (x >= LENGHT || y >= HEIGHT)
        exit (0);
    pixel = (y * LENGHT + x) * 4;
    img_str[0][pixel] = color;
    img_str[0][pixel + 1] = color >> 8;
    img_str[0][pixel + 2] = color >> 16;
}

static void    draw_line(t_points *points, int color, char *img_str)
{
    int dx;
    int dy;
    int p;
    int x;
    int y;
 
	dx = points->x2 - points->x1;
	dy = points->y2 - points->y1;
 
	x = points->x1;
	y = points->y1;
 
	p = 2 * dy - dx;
 
	while( x < points->x2)
	{
        put_pixel(x, y, color, &img_str);
		if(p >= 0)
		{
			y++;
			p += 2 * dy - 2 * dx;
		}
		else
			p += 2 * dy;
		x++;
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
    mlx_hook(data->win_ptr, 2, 0, &key_press, data);
}