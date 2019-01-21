/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_matrix_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 01:33:45 by coremart          #+#    #+#             */
/*   Updated: 2019/01/21 01:33:46 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void    rot_matrix_x(int *y, int *z, const float teta)
{
    int tmp_y;

    tmp_y = *y;
    *y = (int)((float)*y * cos(teta) + (float)*z * sin(teta));
    *z = (int)(-tmp_y * sin(teta) + *z * cos(teta));
}