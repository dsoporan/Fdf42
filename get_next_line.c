/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <dsoporan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:59:53 by dsoporan          #+#    #+#             */
/*   Updated: 2017/01/10 16:34:43 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		reading(int const fd, char **matrix)
{
	char	*str;
	int		bytes;
	char	*tmp;

	str = (char *)malloc(sizeof(*str) * (BUFF_SIZE + 1));
	if (!str)
		return (-1);
	bytes = read(fd, str, BUFF_SIZE);
	if (bytes > 0)
	{
		str[bytes] = '\0';
		tmp = ft_strjoin(*matrix, str);
		free(*matrix);
		*matrix = tmp;
	}
	free(str);
	return (bytes);
}

int				get_next_line(int const fd, char **line)
{
	static char		*matrix = NULL;
	char			*ap;
	int				bytes;

	if ((!matrix && (matrix = (char *)malloc(sizeof(*matrix))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	ap = ft_strchr(matrix, '\n');
	while (ap == NULL)
	{
		bytes = reading(fd, &matrix);
		if (bytes == 0)
		{
			if (ft_strlen(matrix) == 0)
				return (0);
			matrix = ft_strjoin(matrix, "\n");
		}
		if (bytes < 0)
			return (-1);
		else
			ap = ft_strchr(matrix, '\n');
	}
	*line = ft_strsub(matrix, 0, ft_strlen(matrix) - ft_strlen(ap));
	matrix = ft_strdup(ap + 1);
	return (1);
}
