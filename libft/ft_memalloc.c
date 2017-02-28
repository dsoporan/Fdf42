/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:16:06 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/23 21:43:09 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *str;

	if (!size)
		return (0);
	str = malloc(sizeof(*str) * (size));
	if (!str)
		return (0);
	str = ft_memset(str, 0, size);
	return (str);
}
