/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:29:21 by coremart          #+#    #+#             */
/*   Updated: 2019/01/20 19:46:59 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/get_next_line.h"
#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdlib.h>

static size_t map_len(char *line)
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

static void    add_line(t_matrice *last_line, int *line, int len)
{
    t_matrice *new_line;

    if (!(new_line = (t_matrice*)malloc(sizeof(t_matrice))))
        return ;
    new_line->line = ft_memdup(line, len * 4);
    new_line->next = NULL;
    new_line->len = len;
    last_line->next = new_line;
}

static int  *convert_to_int_tab(char *line, size_t *len)
{
    int *tab;
    int i;

    i = 0;
    *len = map_len(line);
    if (!(tab = (int*)malloc(sizeof(int) * *len)))
        return (NULL);
    while (i < (int)*len)
    {
        tab[i++] = ft_atoi(line);
        while ((int)*line == ' ')
            line++;
        while (ft_isdigit((int)*line) || (int)*line == '-')
            line++;
    }
    return (tab);
}

static t_matrice   *new_matrice(int *first_line, size_t len)
{
     t_matrice *new;

     if (!(new = (t_matrice*)malloc(sizeof(t_matrice))))
        return (NULL);
     new->line = ft_memdup(first_line, len * 4);
     new->len = len;
     new->next = NULL;
     return (new);
}

t_matrice		*fill_map(char *path)
{
	int fd;
	char *line;
	size_t len;
	t_matrice *matrice;
	t_matrice *begin;

	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &line))
	{
		matrice = new_matrice(convert_to_int_tab(line, &len), len);
		begin = matrice;
	}
	while (get_next_line(fd, &line))
	{
		add_line(matrice, convert_to_int_tab(line, &len), len);
		matrice = matrice->next;
	}
	return (begin);
}
