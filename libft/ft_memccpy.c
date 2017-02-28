/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:16:23 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/22 19:57:10 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char*)src;
	str2 = (unsigned char*)dest;
	while (i < n)
	{
		str2[i] = str1[i];
		if (str1[i] == (unsigned char)c)
			return (str2 + i + 1);
		i++;
	}
	return (0);
}
