/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:34:21 by coremart          #+#    #+#             */
/*   Updated: 2019/02/05 05:13:26 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
