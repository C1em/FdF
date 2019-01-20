/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:05:17 by coremart          #+#    #+#             */
/*   Updated: 2019/01/20 16:05:18 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

size_t map_len(char *line)
{
    int i;
    size_t res;

    i = 0;
    res = 0;
    while (line[i + 1])
    {
        if (ft_isdigit((int)line[i]) && !ft_isdigit((int)line[i + 1]))
            res++;
        i++;
    }
    if (ft_isdigit((int)line[i]))
        res++;
    return (res);
}