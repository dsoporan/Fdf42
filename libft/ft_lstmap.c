/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 20:35:15 by dsoporan          #+#    #+#             */
/*   Updated: 2016/12/23 20:37:45 by dsoporan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*k;

	new = (t_list *)malloc(sizeof(t_list));
	k = (t_list *)malloc(sizeof(t_list));
	k = f(lst);
	new = k;
	if (new == NULL || lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		k->next = f(lst);
		if ((k->next) == NULL)
			return (NULL);
		k = k->next;
	}
	return (new);
}
