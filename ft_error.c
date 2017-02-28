/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <dsoporan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:42:38 by dsoporan          #+#    #+#             */
/*   Updated: 2017/02/28 13:53:17 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(int err, char *str)
{
	if (err == 1)
	{
		write(1, str, ft_strlen(str));
		return (0);
	}
	else if (err == 2)
	{
		write(1, str, ft_strlen(str));
		exit(0);
	}
	return (0);
}
