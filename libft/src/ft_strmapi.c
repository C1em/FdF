/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:38:26 by coremart          #+#    #+#             */
/*   Updated: 2018/11/12 20:21:01 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s)
	{
		if (!(str = (char*)malloc(ft_strlen(s) + 1)))
			return (NULL);
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = 0;
		return (str);
	}
	return (NULL);
}
