/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <dsoporan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:40:40 by dsoporan          #+#    #+#             */
/*   Updated: 2017/02/25 13:41:30 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_perspective(t_data *data, int key)
{
	if (key == 20)
	{
		data->deg = 0.05;
		expose_hook(data);
	}
}

void	ft_normal(t_data *data, int key)
{
	if (key == 21)
	{
		data->deg = 0.52398776;
		expose_hook(data);
	}
}

void	ft_zoom(t_data *data, int key)
{
	if (key == 78)
	{
		data->space = data->space + 2;
		expose_hook(data);
	}
	if (key == 69 && data->space > 1)
	{
		data->space = data->space - 1;
		expose_hook(data);
	}
}

void	ft_color(t_data *data, int c)
{
	if (c == 18)
	{
		data->color = COLO << 10;
		expose_hook(data);
	}
	if (c == 19)
	{
		data->color = COLO << 18;
		expose_hook(data);
	}
}

int		key_hook(int keyhook, t_data *data)
{
	data->name = "file";
	if (keyhook == ESC)
		exit(0);
	if (keyhook == ZOOMOUT)
		ft_zoom(data, 78);
	if (keyhook == ZOOMIN)
		ft_zoom(data, 69);
	if (keyhook == GREEN)
		ft_color(data, 18);
	if (keyhook == RED)
		ft_color(data, 19);
	if (keyhook == PERSPECTIVE)
		ft_perspective(data, 20);
	if (keyhook == NORMAL)
		ft_normal(data, 21);
	return (0);
}
