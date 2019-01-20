/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:22:09 by coremart          #+#    #+#             */
/*   Updated: 2018/12/04 13:14:53 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 3

typedef struct	s_fd
{
	char		*content;
	int			fd;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
