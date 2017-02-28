/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:24:45 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/23 20:27:39 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_len(char const *s, char c, int i)
{
	size_t tmp;

	tmp = 0;
	while (s[i] && s[i] != c)
	{
		tmp++;
		i++;
	}
	return (tmp);
}

int		ft_cont(char const *s, char c)
{
	int i;
	int ok;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		ok = 1;
		while (s[i] && s[i] == c)
		{
			ok = 0;
			i++;
		}
		while (s[i] && s[i] != c)
		{
			i++;
			ok = 1;
		}
		if (ok)
			count++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len = 0;
	if (!s)
		return (NULL);
	len = ft_cont(s, c);
	if (!(str = (char**)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	while (len > 0)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		str[j] = ft_strsub(s, i, ft_len(s, c, i));
		j++;
		i = i + ft_len(s, c, i);
		len--;
	}
	str[j] = 0;
	return (str);
}
