/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:31:05 by coremart          #+#    #+#             */
/*   Updated: 2019/01/24 16:46:57 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

void    put_pixel(int x, int y, int color, char **img_str)
{
    int pixel;

    if (!(x < LENGHT && y < HEIGHT))
        exit (0);
    pixel = (y * LENGHT + x) * 4;
    img_str[0][pixel] = color;
    img_str[0][pixel + 1] = color >> 8;
    img_str[0][pixel + 2] = color >> 16;
}

void    draw_line(t_points *points, int color, char *img_str)
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

void    draw(t_vector_tab *tab, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < tab->nb_lines)
    {
        j = 0;
        while (j < tab->nb_col)
        {
            draw_line()
            j++;
        }
        i++;
    }
    print_menu(data);
}
