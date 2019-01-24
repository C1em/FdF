/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:40:39 by aljacque          #+#    #+#             */
/*   Updated: 2019/01/24 19:02:05 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/colors.h"
#include <mlx.h>

void	print_menu(t_data *data)
{
	int		x;
	void	*mlx;
	void	*win;

	x = 20;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, x, 10, GRAY, "Fermer le menu : [H]");
	mlx_string_put(mlx, win, x + 1250, 10, RED, "@coremart / @aljacque");
	mlx_string_put(mlx, win, x, 30, GRAY, "Droite, Gauche, Haut, Bas : [<-] [->] [^] [v]");
	mlx_string_put(mlx, win, x, 50, GRAY, "Zoom avant / arriere : [+] / [-]");
	mlx_string_put(mlx, win, x, 70, GRAY, "Changer la couleur : NUMPAD [0] [1] [2] [3] [4]");
	mlx_string_put(mlx, win, x, 90, GRAY, "Modifier l'altitude : [Q] / [E]");
	mlx_string_put(mlx, win, x, 110, GRAY, "Rotation autour de Z, Y, X : [1,2] [3,4] [5,6] [7,8]");
	mlx_string_put(mlx, win, x, 130, GRAY, "Position par defaut : [SPACE]");
	mlx_string_put(mlx, win, x, 150, GRAY, "Quitter : [ESCAPE]");
}
