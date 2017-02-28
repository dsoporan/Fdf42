/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:15:45 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/22 19:52:20 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_null(char *f)
{
	f[0] = '0';
	f[1] = '\0';
	return (f);
}

char	*ft_pos(int n, char *f, int i)
{
	while (n > 0)
	{
		f[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	f[i] = '\0';
	return (f);
}

char	*ft_revstr(char *f, char *j, int k)
{
	char	l;
	int		i;

	i = ft_strlen(f) - 1;
	while (i >= 0 && f[i] != '-')
	{
		l = f[i];
		f[i] = j[k];
		j[k] = l;
		i--;
		k++;
	}
	j[k] = '\0';
	return (j);
}

int		ft_cifre(int i)
{
	int	n;

	n = 0;
	if (i < 0)
		n++;
	if (i == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		n++;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	int		k;
	char	*f;
	char	*j;

	i = 0;
	k = 0;
	f = malloc(sizeof(char) * ft_cifre(n) + 1);
	j = malloc(sizeof(char) * ft_cifre(n) + 1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!f || !j)
		return (0);
	if (n == 0)
		return (ft_null(f));
	if (n < 0)
	{
		n = -n;
		j[k] = '-';
		k++;
	}
	if (n > 0)
		f = ft_pos(n, f, i);
	return (ft_revstr(f, j, k));
}
