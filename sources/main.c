/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:26:43 by coremart          #+#    #+#             */
/*   Updated: 2019/01/19 00:53:12 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FdF.h"

int main(int ac, char **av)
{
	t_matrice *matrice;

	if (ac == 2)
	{
		matrice = fill_map(av[1]);
		print_matrice(matrice);
	}
	return (0);
}
