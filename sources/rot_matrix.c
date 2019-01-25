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
#include <stdlib.h>
#include "../includes/fdf.h"

static void    rot_vector(t_vector *vector, t_angles *angles)
{
    float y;
    float x;
    float z;

    y = (float)vector->y;
    x = (float)vector->x;
    z = (float)vector->z;
    
   vector->y = (int)(cos(-angles->beta) * (x * sin(angles->teta) + y * cos(angles->teta)) + z * sin(-angles->beta));
   vector->z = (int)(-sin(-angles->beta) * (x * sin(angles->teta) + y * cos(angles->teta)) + z * cos(-angles->beta));
   vector->x = (int)(x * cos(angles->teta) - y * sin(angles->teta));
}

void    rot_matrix(t_vector_tab *tab, const float teta, const float beta)
{
    t_angles *angles;

    if (!(angles = (t_angles*)malloc(sizeof(t_angles))))
        return ;
        angles->beta = beta;
        angles->teta = teta;
    foreach_vec(tab, &rot_vector, angles);
}