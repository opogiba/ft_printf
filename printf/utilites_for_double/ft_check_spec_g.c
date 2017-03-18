/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spec_g.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:20:58 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:21:00 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_check_g(int exponent, char *string, t_arg *func, long double nbr)
{
	int len;
	int acc;

	acc = func->acc;
	len = (int)ft_strlen(ft_itoa_base((long int)nbr, 10));
	func->acc = func->acc - len;
	func->acc = func->acc >= 0 ? func->acc : 0;
	if ((exponent < -4) || (exponent >= func->acc && func->acc_ex == 1))
	{
		string = ft_do_exponent_string(nbr, func, exponent);
		return (string);
	}
	else
	{
		func->acc = acc;
		return (NULL);
	}
}
