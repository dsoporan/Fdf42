/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <dsoporan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:44:24 by dsoporan          #+#    #+#             */
/*   Updated: 2017/02/25 13:41:15 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# define WIDTH 600
# define HEIGHT 600
# define DEG30 0.52398776
# define ESC 53
# define ZOOMIN 125
# define ZOOMOUT 126
# define GREEN 18
# define RED 19
# define PERSPECTIVE 20
# define NORMAL 21
# define COLO 0x0004ff

typedef struct	s_coord
{
	int	x;
	int	y;
	int	z;
}				t_coord;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	char	*name;
	t_coord **map;
	int		counter;
	int		color;
	int		sx;
	int		sy;
	int		x;
	int		y;
	int		z;
	int		e;
	int		zoom;
	int		rows;
	int		cols;
	int		space;
	float	deg;
}				t_data;

int				get_next_line(int const fd, char **line);
int				ft_error(int err, char *str);
int				ft_check_map(char **map, t_data *data);
int				ft_check_digit(char **map);
int				ft_check_len(char *map);
int				ft_signdigit(char digit);
int				key_hook(int keyhook, t_data *data);
int				expose_hook(t_data *data);
void			ft_window_init(t_data *data, char *ar);
void			ft_draw_isop(t_data *data, t_coord **iso);
void			ft_draw_lines(t_data *data, t_coord **iso);
void			ft_draw_line(t_data *data, t_coord p1, t_coord p2, int color);
void			ft_color(t_data *data, int c);
void			ft_zoom(t_data *data, int key);
char			**ft_read_to_map(char **map, t_data *data, int fd, char *str);
t_coord			**maptoco(char **map, t_data *data, t_coord **coord, int i);
t_coord			**ft_proj_iso(t_data *data);

#endif
