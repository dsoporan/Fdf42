/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:25:07 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/22 21:04:27 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	length = ft_strlen(s2);
	if (length == 0)
		return ((char*)s1);
	while (s1[i])
	{
		while (s1[i + j] == s2[j])
		{
			if (j == length - 1)
				return ((char*)s1 + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
