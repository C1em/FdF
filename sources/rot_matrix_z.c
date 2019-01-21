/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrix_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 01:46:59 by coremart          #+#    #+#             */
/*   Updated: 2019/01/21 01:47:02 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void    rot_matrix_z(int *x, int *y, const float teta)
{
    int tmp_x;

    tmp_x = *x;
    *x = (int)((float)*x * cos(teta) + (float)*y * sin(teta));
    *y = (int)(-tmp_x * sin(teta) + *y * cos(teta));
}