/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:40:39 by aljacque          #+#    #+#             */
/*   Updated: 2019/01/24 16:45:12 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/colors.h"

void	print_menu(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx;
	win = data->win;
	mlx_string_put(mlx, win, 65, y += 20, YELLOW, "Comment uitliser FdF?");
	//mlx_string_put(mlx, win, 15, y += 35, YELLOW, "Zoom: Scroll ou +/-");
	mlx_string_put(mlx, win, 15, y += 30, YELLOW, "Deplacement: Fleches");
	//mlx_string_put(mlx, win, 15, y += 30, YELLOW, "Flatten: </>");
	//mlx_string_put(mlx, win, 15, y += 30, YELLOW, "Rotation: Click et Deplacement");
	//mlx_string_put(mlx, win, 15, y += 30, YELLOW, "Rotate:");
	//mlx_string_put(mlx, win, 57, y += 25, YELLOW, "X-Axis - 2/8");
	//mlx_string_put(mlx, win, 57, y += 25, YELLOW, "Y-Axis - 4/6");
	//mlx_string_put(mlx, win, 57, y += 25, YELLOW, "Z-Axis - 1(3)/7(9)");
	//mlx_string_put(mlx, win, 15, y += 30, YELLOW, "Projection");
	//mlx_string_put(mlx, win, 57, y += 25, YELLOW, "ISO: I");
	//mlx_string_put(mlx, win, 57, y += 25, YELLOW, "Parallelle: P");
}
