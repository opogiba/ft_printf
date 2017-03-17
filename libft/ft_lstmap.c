/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 23:00:32 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/04 23:13:30 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	if (lst && f)
	{
		new = (*f)(lst);
		first = new;
		while (lst->next)
		{
			new->next = (*f)(lst->next);
			new = new->next;
			lst = lst->next;
		}
	}
	return (first);
}
