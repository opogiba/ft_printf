/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:36:59 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 04:40:39 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_print_float(char *string, t_arg *func, long double nbr)
{
	long long	base;
	char		*first_part;
	char		*second_part;

	nbr = ft_parsing_znak_double(nbr, func);
	if (func->acc_ex == 1 && func->acc == 0)
		nbr = ft_round_fraction(nbr);
	base = (long long)nbr;
	first_part = ft_utoa_base(base, 10, func);
	second_part = (char *)malloc(sizeof(char) * func->acc + 1);
	second_part[func->acc] = '\0';
	if (func->acc > 0 && func->acc <= 15)
		second_part = ft_round_d(nbr - (long double)base, func, second_part);
	else if (func->acc == 0 && func->acc > 15)
		second_part = ft_round(nbr - (long double)base, func, second_part);
	if ((int)ft_strlen(second_part) != func->acc)
		ft_check_len(func->acc, second_part);
	first_part = ft_dot_to_float(first_part, func);
	string = ft_strjoin(first_part, second_part);
	free(first_part);
	free(second_part);
	return (string);
}
