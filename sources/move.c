/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:32:17 by coremart          #+#    #+#             */
/*   Updated: 2019/01/24 18:40:15 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

int    close(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

static void add_to(t_vector *vec, t_param *arrow)
{
    if (arrow->axe == 'x')
    {
        vec->x += arrow->sign_or_key * 10;
        return ;
    }
    vec->y += arrow->sign_or_key * 10;
}

static void key_arrow(int key , t_vector_tab *tab, t_param *arrow)
{
    
    if (key == 123 || key == 126)
        arrow->sign_or_key = -1;
    else
        arrow->sign_or_key = 1;
    if (key == 123 || key == 124)
        arrow->axe = 'x';
    foreach_vec(tab, &add_to, arrow);
}

static void ft_zoom(t_vector *vec, t_param *param)
{
    if (param->sign_or_key == 69)
        {
            vec->x = vec->x * 110.0f / 100.0f;
            vec->y = vec->y * 110.0f / 100.0f;
            vec->z = vec->z * 110.0f / 100.0f;
            return ;
        }
    vec->x = vec->x * 100.0f / 110.0f;
    vec->y = vec->y * 100.0f / 110.0f;
    vec->z = vec->z * 100.0f / 110.0f;
}

static void altitude(t_vector *vec, t_param *param)
{
    (void)vec;
    (void)param;
    /*
    float x;
    float y;
    float z;
    float teta;
    float beta;

    x = vec->x;
    y = vec->y;
    z = vec->z;
    teta = param->angles->total_teta;
    beta = param->angles->total_beta;
    if (param->sign_or_key == 12)
    {
        vec->x = cos(teta) * (x * cos(teta) + z * sin(teta)) +
        ((z * cos(teta) - x * sin(teta)) * cos(beta) - y * sin(beta) - *param->zoom) * sin(teta);
        vec->y = cos(beta) * (y * cos(beta) + z * sin(beta)) +
        ((z * cos(teta) - x * sin(teta)) * cos(beta) - y * sin(beta) - *param->zoom) * sin(teta);
        vec->z = -sin(beta) * (y * cos(beta) + z * sin(beta)) +
        (-sin(teta) * (x * cos(teta) + z * sin(teta)) +
        (cos(beta) * (z * cos(teta) - x * sin(teta)) - y * sin(beta) - *param->zoom) * cos(teta)) * cos(beta);
        return ;
    }
    vec->z *= 1.1f;
    */
}

int         key_press(int key, t_data *data)
{
    t_param *param;

    if (!(param = (t_param*)malloc(sizeof (t_param))))
        return (0);
    param->zoom = &data->tab->zoom;
//    param->angles = data->angles;
    if (key == 53)
        exit(0);
    if (key > 122 && key < 127)
        key_arrow(key, data->tab, param);
    else if ((param->sign_or_key = key) == 69 || param->sign_or_key == 78)
        foreach_vec(data->tab, &ft_zoom, param);
    else if (param->sign_or_key == 12 || param->sign_or_key == 14)
        foreach_vec(data->tab, &altitude, param);
    else
        return (0);
    mlx_destroy_image(data->mlx_ptr, data->img_info->img_ptr);
    data->img_info->img_ptr = mlx_new_image(data->mlx_ptr, LENGHT, HEIGHT);
    data->img_info->img_str = mlx_get_data_addr(data->img_info->img_ptr, &data->img_info->bpp, &data->img_info->len, &data->img_info->endian);
    draw(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_info->img_ptr, 0, 0);
    print_menu(data);
    return (0);
}
