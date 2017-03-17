/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:56:46 by opogiba           #+#    #+#             */
/*   Updated: 2016/11/30 23:14:00 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = (void*)malloc(sizeof(void) * size);
	if (a == NULL)
		return (NULL);
	while (i < size)
	{
		a[i] = 0;
		i++;
	}
	return ((void*)a);
}
