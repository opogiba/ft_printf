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

char	*ft_do_first_hex_string(char *final, t_arg *func, double long nbr)
{
	final = ft_strdup("");
	func->f_hash = 1;
	if (func->chr == 'A')
		func->chr = 'X';
	else
		func->chr = 'x';
	if (nbr == 0.0)
		final = ft_join_char(final, 0, '0');
	else if (nbr > 0.0 || nbr < 0.0)
		final = ft_join_char(final, 0, '1');
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

char 	*ft_do_fraction_string(char *final, t_arg *func, long double nbr)
{
	int i;
	int base;
	int j;

	j = 0;
	i = func->acc;
	final = (char*)malloc(sizeof(char) * i + 1);
	base = (int)nbr;
	nbr = nbr - (long double)base;
	while (func->acc )
	{
		nbr = nbr * 16;
		base = (int)nbr;
		nbr = nbr -(long double)base;
		if(base >= 10)
			final[j] = base - 10 + func->chr - 23;
		else
			final[j] = base +'0';
		j++;
		func->acc--;
	}
	final[j] = '\0';
	return (final);
}

char 	*ft_del_zer(char *second_part, char *fin, t_arg *func)
{
	int i;
	int j;

	j = (int)ft_strlen(second_part) - 1;
	i = j;
//	if(func ->acc_ex != -1)
//		i--;
	while (j  >=  0 && func->acc_ex == -1)
	{
		if (second_part[j] != '0')
		{
			i--;
			break;
		}
		if (second_part[j] == '0')
		{
			second_part[j] = '\0';
			i--;
		}
		j--;
	}
	if (j == 0)
		return (fin);
	fin = ft_join_char(fin, 0, '.');
	return (fin);
}

char	*ft_do_hex_d(char *fin, t_arg *func, long double nbr, int exp)
{
	char *second_part;
	char *third_part;
	char *tmp;

	third_part = NULL;
	if (func->acc_ex != 1)
	{
		func->acc = ft_count_acc_for_a(nbr);
		func->acc_ex = -1 ;
	}
	second_part = ft_do_fraction_string(second_part, func, nbr);
	fin = ft_del_zer(second_part, fin, func);
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
