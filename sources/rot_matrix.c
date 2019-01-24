/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:44:08 by coremart          #+#    #+#             */
/*   Updated: 2019/01/21 23:44:12 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/fdf.h"

static void    rot_vector(t_vector *vector, const float teta, const float beta)
{
    float tmp_y;

    tmp_y = (float)vector->y;
    vector->y = (int)((-(float)vector->x * sin(teta) +
    (float)vector->y * cos(teta)) * cos(beta) + (float)vector->z * sin(beta));
    vector->x = (int)((float)vector->x * cos(teta) + (float)vector->y * sin(teta));
    vector->z = (int)(-tmp_y * sin(beta) + vector->z * cos(beta));
}

t_vector    **rot_matrix(t_vector_tab *tab, const float teta, const float beta)
{
    int i;
    int j;

    i = 0;
    while(i < tab->nb_lines)
    {
        j = 0;
        while(j < tab->nb_col)
            rot_vector(&tab->tab[i][j++], teta, beta);
        i++;
    } 
}