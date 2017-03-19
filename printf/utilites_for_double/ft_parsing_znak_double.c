/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_znak_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 04:49:05 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:20:15 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

long double	ft_parsing_znak_double(long double nbr, t_arg *func)
{
	if (nbr < 0 || nbr == -0.0)
	{
		func->f_plus = 1;
		nbr = -nbr;
	}
	if (func->f_plus == 1)
		func->f_space = 0;
	if (func->f_minus == 1)
		func->f_zero = 0;
	return (nbr);
}
