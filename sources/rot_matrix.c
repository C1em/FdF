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
    float y;
    float x;
    float z;

    y = (float)vector->y;
    x = (float)vector->x;
    z = (float)vector->z;
    /*
 //   vector->y = (int)((-(float)vector->x * sin(teta) + (float)vector->y * cos(teta)) * cos(beta) + (float)vector->z * sin(beta));
    vector->y = (int)(vector->y * cos(beta) + (float)vector->z * sin (beta));
 //   vector->z = (int)(((float)vector->x * sin(teta) -tmp_y * cos(teta)) * sin(beta) + vector->z * cos(beta));
    vector->z = (int)(-tmp_y * sin (beta) + cos(beta));
    vector->x = (int)((float)vector->x * cos(teta) + (float)vector->y * sin(teta));
    */
   vector->y = (int)(cos(beta) * (x * sin(teta) + y * cos(teta)) + z * sin(beta));
   vector->z = (int)(-sin(beta) * (x * sin(teta) + y * cos(teta)) + z * cos(beta));
   vector->x = (int)(x * cos(teta) - y * sin(teta));

}

void    rot_matrix(t_vector_tab *tab, const float teta, const float beta)
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