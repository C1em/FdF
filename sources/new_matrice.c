/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:17:15 by coremart          #+#    #+#             */
/*   Updated: 2019/01/20 19:47:12 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>

t_matrice   *new_matrice(int *first_line, size_t len)
{
     t_matrice *new;

     if (!(new = (t_matrice*)malloc(sizeof(t_matrice))))
        return (NULL);
     new->line = ft_memdup(first_line, len * 4);
     new->len = len;
     new->y = 0;
     new->next = NULL;
     return (new);
}
