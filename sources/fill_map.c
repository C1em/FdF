/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:29:21 by coremart          #+#    #+#             */
/*   Updated: 2019/01/19 01:17:14 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include "FdF.h"
#include <fcntl.h>
#include <stdlib.h>

t_matrice		*fill_map(char *path)
{
	int fd;
	char *line;
	t_matrice *matrice;
	t_matrice *begin;

	fd = open(path, O_RDONLY);
	if (get_next_line(fd, &line))
	{
		matrice = new_matrice(convert_to_int_tab(line), map_len(line));
		begin = matrice;
	}
	while (get_next_line(fd, &line))
	{
		add_line(matrice, convert_to_int_tab(line), map_len(line));
		matrice = matrice->next;
	}
	return (begin);
}