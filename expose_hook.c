/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <dsoporan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:43:36 by dsoporan          #+#    #+#             */
/*   Updated: 2017/02/28 15:27:59 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_lines(t_data *data, t_coord **iso)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows - 1)
	{
		j = 0;
		while (j < data->cols - 1)
		{
			ft_draw_line(data, iso[i][j], iso[i][j + 1], data->color);
			ft_draw_line(data, iso[i][j], iso[i + 1][j], data->color);
			j++;
		}
		i++;
	}
}

t_coord	**ft_proj_iso(t_data *data)
{
	t_coord	**map;
	int		i;
	int		j;

	i = 0;
	map = (t_coord**)malloc(sizeof(t_coord) * data->rows);
	while (i < data->rows)
	{
		map[i] = (t_coord*)malloc(sizeof(t_coord) * data->cols);
		j = 0;
		while (j < data->cols)
		{
			map[i][j].x = WIDTH / 2 + data->map[i][j].x
				* data->space * cos(data->deg) - data->map[i][j].y
				* data->space * cos(data->deg);
			map[i][j].y = HEIGHT / 2 + data->map[i][j].x
				* data->space * sin(data->deg) + data->map[i][j].y * data->space
				* sin(data->deg) - data->map[i][j].z * data->space;
			map[i][j].z = data->map[i][j].z;
			j++;
		}
		i++;
	}
	return (map);
}

int		expose_hook(t_data *data)
{
	t_coord **iso;

	iso = ft_proj_iso(data);
	mlx_clear_window(data->mlx, data->win);
	ft_draw_lines(data, iso);
	return (0);
}
