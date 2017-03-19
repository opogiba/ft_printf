/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:37:09 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/19 20:39:37 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static double	nth_root(double a, int n)
{
	int		k;
	double	x[6];

	x[0] = 1;
	k = 0;
	while (k < 6 - 1)
	{
		x[k + 1] = (1.0 / n) * ((n - 1) * x[k] + a / ft_pow(x[k], n - 1));
		k++;
	}
	return (x[6 - 1]);
}

double			ft_pow(double base, double ex)
{
	double half_pow;

	if (base == 0)
		return (0);
	if (ex == 0)
		return (1);
	else if (ex < 0)
		return (1 / ft_pow(base, -ex));
	else if (ex > 0 && ex < 1)
		return (nth_root(base, (int)(1 / ex)));
	else if ((int)ex % 2 == 0)
	{
		half_pow = ft_pow(base, ex / 2);
		return (half_pow * half_pow);
	}
	else
		return (base * ft_pow(base, ex - 1));
}
