/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:26:43 by coremart          #+#    #+#             */
/*   Updated: 2019/03/04 08:15:44 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <errno.h>

t_data	*window_init(void)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		ft_error(errno);
	if (!(data->img_info = (t_img_info*)malloc(sizeof(t_img_info))))
		ft_error(errno);
	if (!(data->points = (t_points*)malloc(sizeof(t_points))))
		ft_error(errno);
	if (!(data->mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		ft_error(errno);
	data->mouse->pressed = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, LENGHT, HEIGHT, "FdF");
	data->img_info->img_ptr = mlx_new_image(data->mlx_ptr, LENGHT, HEIGHT);
	data->img_info->img_str = mlx_get_data_addr(data->img_info->img_ptr,
		&data->img_info->bpp, &data->img_info->len, &data->img_info->endian);
	data->menu_open = 0;
	return (data);
}

int		main(int ac, char **av)
{
	t_data *data;

	if (ac != 2)
		ft_error(-3);
	data = window_init();
	data->matrix = fill_map((const char*)av[1]);
	data->tab = convert_to_vector(data->matrix);
	draw(data);
	mlx_loop(data->mlx_ptr);
	free(data->img_info);
	free(data->points);
	free(data->mouse);
	free_tab(data->tab);
	free(data->tab);
	free_lst(data->matrix);
	free(data);
	while (1)
		;
	return (0);
}
