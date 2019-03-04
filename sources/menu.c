/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:40:39 by aljacque          #+#    #+#             */
/*   Updated: 2019/03/04 05:03:25 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

#define GREY 0x828FA6
#define RED 0xD05350

void	print_menu(t_data *data)
{
	if (data->menu_open)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 10, GREY,
				"Close menu : [H]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20 + 1250, 10, RED,
				"@coremart / @aljacque");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 30, GREY,
				"Right, Left, Top, Bottom : [<-] [->] [^] [v]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 50, GREY,
				"Zoom forward / backward : [+] / [-]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 70, GREY,
				"Change color : NUMPAD [0] [1] [2] [3]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 90, GREY,
				"Modify altitude: : [Q] / [E]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 130, GREY,
				"default position : [SPACE]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 150, GREY,
				"Quit : [ESCAPE]");
	}
	else
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 10, GREY,
				"Open menu : [H]");
}
