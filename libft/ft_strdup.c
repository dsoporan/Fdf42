/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:21:55 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/22 20:46:12 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char *str;

	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (0);
	else
		ft_strcpy(str, s);
	return (str);
}
