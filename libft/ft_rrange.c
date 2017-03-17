/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:03:00 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/06 21:19:43 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int		ft_check(int start, int end)
{
	if (start == end)
		return (1);
	if (start > end)
		return (start - end);
	if (end > start)
		return (end - start);
	return (0);
}

int				*ft_rrange(int start, int end)
{
	int i;
	int *array;

	i = 0;
	array = NULL;
	array = (int*)malloc(sizeof(int) * (ft_check(start, end) + 1));
	if (start > end)
	{
		while (end != start)
			array[i++] = end++;
		array[i] = end;
	}
	else if (start < end)
	{
		while (end != start)
			array[i++] = end--;
		array[i] = end;
	}
	else if (start == end)
		array[i] = end;
	return (array);
}
