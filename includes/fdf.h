/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:48:33 by coremart          #+#    #+#             */
/*   Updated: 2019/01/19 00:50:02 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
#define _FDF_H_

#include <string.h>
typedef struct  s_matrice
{
    int *line;
    int y;
    size_t len;
    struct s_matrice *next;
}               t_matrice;

t_matrice   *fill_map(char * path);
t_matrice   *new_matrice(int *first_line, size_t len);
void        add_line(t_matrice *last_line, int *line, int len);
int         *convert_to_int_tab(char *line);
void        print_matrice(t_matrice *matrice);
size_t      map_len(char *line);

#endif