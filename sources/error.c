/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 04:32:26 by coremart          #+#    #+#             */
/*   Updated: 2019/02/05 05:09:30 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"

void	ft_error(int errnum)
{
	if (errnum == -1)
	{
		ft_putendl("error : empty file");
		exit(1);
	}
	strerror(errnum);
	exit(1);
}
