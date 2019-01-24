/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:30:32 by coremart          #+#    #+#             */
/*   Updated: 2019/01/21 18:30:33 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

void    find_mid(t_matrice *matrix, float *mid_x, float *mid_y, int *zoom)
{
    int y;

    y = 0;
    *mid_x = (matrix->len - 1) / 2;
    while (matrix->next)
    {
        matrix = matrix->next;
        y++;
    }
    *zoom = ((LENGHT / matrix->len > LENGHT / (y + 1)) ? LENGHT / matrix->len : LENGHT / (y + 1));
    *mid_y = y / 2;
}

static size_t  count_line(t_matrice *matrix)
{
    size_t i;

    i = 0;
    while (matrix)
    {
        matrix = matrix->next;
        i++;
    }
    return (i);
}

t_vector_tab    *convert_to_vector(t_matrice *matrix)
{
    float mid_x;
    float mid_y;
    int zoom;
    size_t i;
    int j;
    t_vector_tab *vector_tab;

    find_mid(matrix, &mid_x, &mid_y, &zoom);
    if (!(vector_tab = (t_vector_tab*)malloc(sizeof(t_vector_tab))))
        return (NULL);
    vector_tab->nb_lines = count_line(matrix);
    if (!(vector_tab->tab = (t_vector**)malloc(sizeof(t_vector*) * vector_tab->nb_lines)))
        return (NULL);
    i = 0;
    while (i < vector_tab->nb_lines)
    {
        j = 0;
        if (!(vector_tab->tab[i] = (t_vector*)malloc(sizeof(t_vector) * matrix->len)))
            return (NULL);
        while (j < matrix->len)
        {
            vector_tab->tab[i][j].x = zoom * (j - mid_x);
            vector_tab->tab[i][j].y = zoom * (i - mid_y);
            vector_tab->tab[i][j].z = matrix->line[j];
            j++;
        }
        matrix = matrix->next;
        i++;
    }
    vector_tab->nb_col = matrix->len;
    return (vector_tab);
}