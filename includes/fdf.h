/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:48:33 by coremart          #+#    #+#             */
/*   Updated: 2019/01/24 18:38:56 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
#define _FDF_H_

#define LENGHT 1500.0f
#define HEIGHT 1000.0f
#define PI 3.14159265359f

#include <string.h>

typedef struct  s_points
{
	int x1;
	int y1;
	int x2;
	int y2;
}               t_points;

typedef struct  s_img_info
{
	void *img_ptr;
	char *img_str;
	int bpp;
	int len;
	int endian;
}               t_img_info;

typedef struct  s_vector
{
	float x;
	float y;
	float z;
}               t_vector;

typedef struct	s_rot
{
	float teta;
	t_vector *vec;
}				t_rot;

typedef struct s_param
{
	int *zoom;
	char axe;
	int sign_or_key;
}				t_param;

typedef struct  s_vector_tab
{
	t_vector **tab;
	int nb_lines;
	int nb_col;
	int zoom;
}               t_vector_tab;

typedef struct  s_matrice
{
	int *line;
	size_t len;
	struct s_matrice *next;
}               t_matrice;

typedef struct	s_mouse
{
	int previous_x;
	int previous_y;
	int x;
	int y;
	int pressed;
}				t_mouse;

typedef struct  s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img_info *img_info;
	t_points *points;
	t_vector_tab *tab;
	t_mouse *mouse;
}               t_data;

t_matrice   	*fill_map(char * path);
int         	key_events(int keycode);
int         	ft_open_window(void);
t_vector_tab    *convert_to_vector(t_matrice *matrix);
void			rot_matrix(t_vector_tab *tab, float x, float y);
void    		draw(t_data *data);
int     		key_press(int key, t_data *data);
void			print_menu(t_data *data);
void			foreach_vec(t_vector_tab *tab, void (*fun)(), void *param);
int				mouse_press(int button, int x, int y, t_mouse *mouse);
int				mouse_release(int button, int x, int y, t_mouse *mouse);
int				mouse_move(int x, int y, t_data *data);
int				close(void *param);

#endif
