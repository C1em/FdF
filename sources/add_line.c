/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:25:39 by coremart          #+#    #+#             */
/*   Updated: 2019/01/20 19:46:55 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>

void    add_line(t_matrice *last_line, int *line, int len)
{
    t_matrice *new_line;

    if (!(new_line = (t_matrice*)malloc(sizeof(t_matrice))))
        return ;
    new_line->line = ft_memdup(line, len * 4);
    new_line->y = last_line->y + 1;
    new_line->next = NULL;
    new_line->len = len;
    last_line->next = new_line;
}
