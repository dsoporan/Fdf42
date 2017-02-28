/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:25:36 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/23 21:43:28 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		how_many_spaces(const char *s)
{
	int i;
	int sum;
	int j;

	i = 0;
	sum = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s))
		return (0);
	sum = i;
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		j++;
		i--;
	}
	sum = sum + j;
	return (ft_strlen(s) - sum);
}

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) -
				how_many_spaces(s) + 1));
	if (!str)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	ft_strcpy(str, s + i);
	i = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i--;
	str[i + 1] = '\0';
	return (str);
}
