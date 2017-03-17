/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:56:27 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/06 19:56:31 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		count(int n)
{
	long	ac;
	int		i;

	i = 0;
	ac = n;
	if (n < 0)
	{
		i++;
		ac = -ac;
	}
	while (ac >= 10)
	{
		ac = ac / 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	long	i;
	char	*array;
	long	ab;

	ab = n;
	i = count(n);
	array = NULL;
	if ((array = (char*)malloc(sizeof(char) * (i + 1))))
	{
		array[0] = '0';
		array[i] = '\0';
		if (n < 0)
		{
			array[0] = '-';
			ab = -ab;
		}
		i--;
		while (ab > 0)
		{
			array[i] = (ab % 10) + '0';
			i--;
			ab = ab / 10;
		}
	}
	return (array);
}
