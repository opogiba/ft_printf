/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:45:02 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/06 21:15:40 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_iterative_factorial(int nb)
{
	int a;
	int i;

	a = 1;
	i = 1;
	if (nb < 0)
		return (0);
	else
	{
		while (a <= nb)
		{
			a = a * i;
			i++;
		}
		return (a);
	}
}
