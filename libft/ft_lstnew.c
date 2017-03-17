/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 21:18:53 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/04 23:14:30 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		node->content = (void *)malloc(content_size);
		if (content)
		{
			node->content = ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
		else
		{
			node->content = NULL;
			node->content_size = 0;
		}
		node->next = NULL;
	}
	return (node);
}
