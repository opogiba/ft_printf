/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:21:58 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:22:02 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

long double	ft_ceil(long double fraction)
{
	long double	nbr;

	nbr = (long long)fraction;
	if (fraction <= nbr)
		return (nbr);
	return (nbr + 1);
}

long double	ft_floor(long double fraction)
{
	long double	nbr;

	nbr = (long long)fraction;
	if (fraction >= nbr)
		return (nbr);
	return (nbr - 1);
}

long double	ft_round_fraction(long double fract)
{
	if (fract - ft_floor(fract) == 0.5 && (long long)ft_floor(fract) % 2 == 0)
		return (ft_floor(fract));
	else if (ft_ceil(fract) - fract == 0.5)
		return (ft_ceil(fract));
	if (fract - ft_floor(fract) >= 0.5)
		return (ft_ceil(fract));
	else
		return (ft_floor(fract));
}
