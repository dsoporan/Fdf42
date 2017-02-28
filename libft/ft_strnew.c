/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:24:08 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/23 21:28:25 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *str;

	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	while (size > 0)
	{
		str[size] = '\0';
		size--;
	}
	return (str);
}
