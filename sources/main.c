/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:30:04 by aljacque          #+#    #+#             */
/*   Updated: 2019/01/20 19:13:35 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include "../includes/fdf.h"
#include "../includes/keys.h"

typedef struct    s_fdf
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 t_fdf;

int			key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	return (0);
}

int		close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int main(void)
{
    t_fdf        fdf;

    if ((fdf.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((fdf.mlx_win = mlx_new_window(fdf.mlx_ptr, 2560, 1440, "FdF")) == NULL)
        return (EXIT_FAILURE);
    mlx_hook(fdf->win, 2, 0, key_press, fdf);
    if (key == MAIN_PAD_ESC)
        exit(0);
    return (EXIT_SUCCESS);
}
