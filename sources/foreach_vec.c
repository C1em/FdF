/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:34:21 by coremart          #+#    #+#             */
/*   Updated: 2019/03/04 05:02:59 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	foreach_vec(t_vector_tab *tab, void (*fun)(), void *param)
{
	int i;
	int j;

	i = 0;
	while (i < tab->nb_lines)
	{
		j = 0;
		while (j < tab->nb_col)
			fun(&tab->tab[i][j++], param);
		i++;
	}
}
