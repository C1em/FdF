/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_int_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:40:58 by coremart          #+#    #+#             */
/*   Updated: 2019/01/20 19:46:53 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/fdf.h"

int  *convert_to_int_tab(char *line)
{
    int *tab;
    int i;
    int len;

    i = 0;
    len = map_len(line);
    if (!(tab = (int*)malloc(sizeof(int) * len)))
        return (NULL);
    while (i < len)
    {
        tab[i++] = ft_atoi(line);
        while ((int)*line == ' ')
            line++;
        while (ft_isdigit((int)*line) || (int)*line == '-')
            line++;
    }
    return (tab);
}
