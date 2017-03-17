/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:36:59 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/17 16:37:17 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char 	*ft_print_float(char *string, t_arg *func, long double nbr)
{
	long long	exponenta;
	char  *string1;
	char *string2;

	nbr = ft_parsing_znak_double(nbr, func);
	if (func->acc_ex == 1 && func->acc == 0)
		nbr = ft_r_nbr(nbr);
	exponenta = (long long)nbr;
	if((long double)exponenta < nbr)
		nbr = ft_r_nbr(nbr);
	string1 = ft_utoa_base(exponenta,10,func);
	string2 = (char *)malloc(sizeof(char) * func->acc + 1);
	if(func->acc > 0 && func->acc <= 15)
		string2 = ft_round_d(nbr - (long double)exponenta, func, string2);
	else if(func->acc == 0 && func->acc > 15)
		string2 = ft_round(nbr - (long double)exponenta, func, string2);
	if((int)ft_strlen(string2) != func->acc)
		ft_check_len((int)ft_strlen(string2), func->acc, string2);
	string1 = ft_dot_to_float(string1, func);
	string = ft_strjoin(string1, string2);
	free(string1);
	free(string2);
	return (string);
}