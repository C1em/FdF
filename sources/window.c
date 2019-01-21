/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:59:36 by aljacque          #+#    #+#             */
/*   Updated: 2019/01/20 20:34:30 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include "../includes/fdf.h"

int		key_events(int keycode)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int ft_open_window(void)
{
    t_mlx        *data;

    if (!(data = malloc(sizeof(t_mlx))))
        return (EXIT_FAILURE);
    if ((data->mlx = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data->wiw = mlx_new_window(data->mlx, 2560, 1440, "FdF")) == NULL)
        return (EXIT_FAILURE);
    mlx_hook(data->wiw, 2, 0, key_events, 0);
    mlx_loop(data->mlx);
    return (EXIT_SUCCESS);
}
