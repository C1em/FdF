/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 06:11:25 by coremart          #+#    #+#             */
/*   Updated: 2019/03/04 05:03:15 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_color_to_vec(t_vector *vec, int *color)
{
	if (vec->color)
		vec->color = *color;
}

void		ft_color(int key, t_vector_tab *tab)
{
	int color_tab[8];

	color_tab[0] = 0xFFFFFF;
	color_tab[1] = 0xFFFFFF;
	color_tab[2] = 0x005800;
	color_tab[3] = 0x845040;
	color_tab[4] = 0x727639;
	color_tab[5] = 0x7CF4E5;
	color_tab[6] = 0xfdff00;
	color_tab[7] = 0xFF0000;
	tab->color = color_tab[(key - 82) * 2];
	foreach_vec(tab, &put_color_to_vec, &color_tab[(key - 82) * 2 + 1]);
}
