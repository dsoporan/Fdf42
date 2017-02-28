/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <dsoporan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:40:22 by dsoporan          #+#    #+#             */
/*   Updated: 2017/02/28 13:57:36 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_read_to_map(char **map, t_data *data, int fd, char *str)
{
	int	rows;

	rows = 0;
	map = (char **)malloc(sizeof(*map) * 1024);
	while (get_next_line(fd, &str) > 0)
	{
		map[rows] = str;
		rows++;
	}
	data->rows = rows;
	return (map);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	t_coord	**coord;
	char	**map;
	int		fd;

	map = NULL;
	if (argc != 2)
		ft_error(2, "Invalid argv\n");
	data = (t_data *)malloc(sizeof(t_data));
	coord = (t_coord **)malloc(sizeof(t_coord));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(2, "Invalid file\n");
	map = ft_read_to_map(map, data, fd, argv[1]);
	if (ft_check_map(map, data) != 0)
		ft_error(2, "Invalid map\n");
	data->map = maptoco(map, data, coord, 0);
	ft_strdel(map);
	data->zoom = 30;
	ft_window_init(data, argv[1]);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
