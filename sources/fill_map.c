/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:29:21 by coremart          #+#    #+#             */
/*   Updated: 2019/02/06 16:50:05 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include <stdio.h>

static size_t		map_len(const char *line)
{
	int		i;
	size_t	res;

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

static void			add_line(t_matrice *last_line, int *line, const size_t len)
{
	t_matrice *new_line;

	if (!(new_line = (t_matrice*)malloc(sizeof(t_matrice))))
		ft_error(errno);
	if (!(new_line->line = ft_memdup(line, len * 4)))
		ft_error(12);
	new_line->next = NULL;
	new_line->len = len;
	free(line);
	last_line->next = new_line;
}

static int			*convert_to_int_tab(char *line, const size_t len)
{
	int		*tab;
	size_t	i;

	i = 0;
	if (map_len((const char*)line) != len)
		ft_error(-2);
	if (!(tab = (int*)malloc(sizeof(int) * len)))
		ft_error(errno);
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

static t_matrice	*new_matrice(int *first_line, const size_t len)
{
	t_matrice *new;

	if (!(new = (t_matrice*)malloc(sizeof(t_matrice))))
		ft_error(errno);
	if (!(new->line = ft_memdup(first_line, len * 4)))
		ft_error(errno);
	new->len = len;
	new->next = NULL;
	free(first_line);
	return (new);
}

t_matrice			*fill_map(const char *path)
{
	int			fd;
	char		*line;
	size_t		len;
	t_matrice	*matrice;
	t_matrice	*begin;

	if (!(fd = open(path, O_RDONLY)))
		ft_error(errno);
	if (get_next_line(fd, &line) != 1)
		ft_error(-1);
	len = map_len((const char*)line);
	matrice = new_matrice(convert_to_int_tab(line, (const size_t)len),
		(const size_t)len);
	begin = matrice;
	while (get_next_line(fd, &line))
	{
		add_line(matrice, convert_to_int_tab(line, (const size_t)len),
			(const size_t)len);
		matrice = matrice->next;
	}
	if (close(fd) == -1)
		ft_error(errno);
	return (begin);
}
