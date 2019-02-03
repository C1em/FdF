/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 03:00:44 by coremart          #+#    #+#             */
/*   Updated: 2019/02/03 03:00:46 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

void    free_tab(t_vector_tab *tab)
{
    int i;

    i = 0;
    while (i < tab->nb_lines)
        free(tab->tab[i++]);
}

void    free_lst(t_matrice *matrix)
{
    while (matrix)
    {
        free(matrix->line);
        matrix = matrix->next;
    }
}