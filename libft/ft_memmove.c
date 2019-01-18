/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:47:00 by coremart          #+#    #+#             */
/*   Updated: 2018/11/16 13:46:23 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((unsigned char*)src <= (unsigned char*)dst)
		while (len--)
			*((unsigned char*)dst + len) = *((unsigned char*)src + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
