/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <dsoporan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:40:54 by dsoporan          #+#    #+#             */
/*   Updated: 2017/02/25 13:29:48 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_window_init(t_data *data, char *ar)
{
	data->name = ar;
	data->deg = 0.52398776;
	data->color = COLO;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	data->space = (WIDTH) / (data->cols + data->zoom);
}
