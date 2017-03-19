/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_hexdecimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:24:52 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/19 20:44:21 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_do_hex_d(char *fin, t_arg *func, long double nbr, int exp)
{
	char *second_part;
	char *third_part;
	char *tmp;

	second_part = NULL;
	third_part = NULL;
	if (func->acc_ex != 1)
	{
		func->acc = ft_count_acc_for_a(nbr);
		func->acc_ex = -1 ;
	}
	second_part = ft_do_fraction_string(second_part, func, nbr);
	fin = ft_del_z(second_part, fin, func);
	third_part = ft_do_last_hex_string(third_part, func, exp);
	tmp = fin;
	fin = ft_strjoin(fin, second_part);
	free(tmp);
	free(second_part);
	tmp = fin;
	fin = ft_strjoin(fin, third_part);
	free(tmp);
	free(third_part);
	return (fin);
}

char	*ft_print_hex_double(char *string, t_arg *func, double long nbr)
{
	int					exponent;

	exponent = 0;
	nbr = ft_parsing_znak_double(nbr, func);
	string = ft_do_first_hex_string(string, func, nbr);
	if (nbr < 1 && nbr != 0.0)
	{
		while ((unsigned long long)nbr != 1)
		{
			nbr = nbr * 2;
			exponent--;
		}
	}
	if (nbr >= 2 && nbr != 0.0)
	{
		while ((unsigned long long)nbr != 1)
		{
			nbr = nbr / 2;
			exponent++;
		}
	}
	return (ft_do_hex_d(string, func, nbr, exponent));
}
