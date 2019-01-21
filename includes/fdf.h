/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:48:33 by coremart          #+#    #+#             */
/*   Updated: 2019/01/20 20:34:10 by aljacque         ###   ########.fr       */
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
    void          *mlx_ptr;
    void          *mlx_win;
}               t_matrice;

typedef struct	s_mlx
{
	void		*mlx;
	void		*wiw;
}				t_mlx;

t_matrice   *fill_map(char * path);
t_matrice   *new_matrice(int *first_line, size_t len);
void        add_line(t_matrice *last_line, int *line, int len);
int         *convert_to_int_tab(char *line);
void        print_matrice(t_matrice *matrice);
size_t      map_len(char *line);
int         key_events(int keycode);
int         ft_open_window(void);

#endif
