/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_hexdecimal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:24:52 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 20:26:56 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_do_first_hex_string(char *final, t_arg *func, double long nbr)
{
	final = ft_strdup("");
//	final = ft_join_char(final, 0, '0');
	func->f_hash = 1;
	if (func->chr == 'A')
	{
//		final = ft_join_char(final, 0, 'X');
		func->chr = 'X';
	}
	else
		func->chr = 'x';

//		final = ft_join_char(final, 0, 'x');
	if (nbr == 0.0 && func->acc_ex == 0)
		final = ft_join_char(final, 0, '0');
	else
		final = ft_join_char(final, 0, '1');
	if(nbr != 0.0)
		final = ft_join_char(final, 0, '.');
	return (final);
}

char	*ft_do_last_hex_string(char *final, t_arg *func, int exponent)
{
	char	*tmp;

	final = ft_strdup("");
	if (func->chr == 'X')
		final = ft_join_char(final, 0, 'P');
	else
		final = ft_join_char(final, 0, 'p');
	if (exponent < 0)
		final = ft_join_char(final, 0, '-');
	else
		final = ft_join_char(final, 0, '+');
	if (exponent < 0)
		exponent *= -1;
	tmp = final;
	final = ft_strjoin(final, ft_itoa_base(exponent, 10));
	free(tmp);
	return (final);
}

char	*ft_do_hex_d(char *fin, t_arg *func, double long nbr, int exp)
{
	char *first_part;
	char *second_part;
	char *third_part;
	int i;

	i = func->acc;

	first_part = NULL;
	second_part = ft_strdup("");
	third_part = NULL;
	first_part = ft_do_first_hex_string(first_part, func, nbr);
	if (func->acc_ex != 1)
		func->acc = ft_count_acc_for_a(nbr);
	while (func->acc && (nbr > 0.0 || nbr < 0.0))
	{
		nbr = nbr * 16;
		func->acc--;
	}
	if(nbr > 0.0 || nbr < 0.0)
		second_part = ft_utoa_base((unsigned long long)(nbr), 16, func);
	if ((int)ft_strlen(second_part) != func->acc)
		ft_check_len(i, second_part);
	third_part = ft_do_last_hex_string(third_part, func, exp);
	fin = ft_strjoin(first_part, second_part);
	free(first_part);
	first_part = fin;
	free(second_part);
	fin = ft_strjoin(fin, third_part);
	free(first_part);
	free(third_part);
	return (fin);
}

char	*ft_print_hex_double(char *string, t_arg *func, double long nbr)
{
	unsigned long long	base;
	int					exponent;

	exponent = 0;
	nbr = ft_parsing_znak_double(nbr, func);
	base = (unsigned long long)nbr;
	if (nbr < 1 && nbr != 0.0)
	{
		while (base != 1)
		{
			nbr = nbr * 2;
			base = (unsigned long long)nbr;
			exponent--;
		}
	}
	if (nbr >= 2 && nbr != 0.0)
	{
		while (base != 1)
		{
			nbr = nbr / 2;
			base = (unsigned long long)nbr;
			exponent++;
		}
	}
	return (ft_do_hex_d(string, func, nbr - (long double)base, exponent));
}
