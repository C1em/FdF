/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:40:39 by aljacque          #+#    #+#             */
/*   Updated: 2019/02/05 05:32:27 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/colors.h"
#include <mlx.h>

void	print_menu(t_data *data)
{
	if (data->menu_open)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 10, GRAY,
				"Close menu : [H]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20 + 1250, 10, RED,
				"@coremart / @aljacque");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 30, GRAY,
				"Right, Left, Top, Bottom : [<-] [->] [^] [v]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 50, GRAY,
				"Zoom forward / backward : [+] / [-]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 70, GRAY,
				"Change color : NUMPAD [0] [1] [2] [3]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 90, GRAY,
				"Flatten map : [Q] / [E]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 130, GRAY,
				"default position : [SPACE]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 150, GRAY,
				"Quit : [ESCAPE]");
	}
	else
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 10, GRAY,
				"Open menu : [H]");
}
