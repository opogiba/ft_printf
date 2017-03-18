/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exponent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:32:47 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 04:39:19 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_sec_part_exp(char *second_part, t_arg *func, int exponent)
{
	if (exponent > -10 && exponent < 10)
		second_part = ft_join_char(second_part, 1, '0');
	if (exponent < 0)
		second_part = ft_join_char(second_part, 1, '-');
	else
		second_part = ft_join_char(second_part, 1, '+');
	if (func->chr >= 97 && func->chr <= 122)
		second_part = ft_join_char(second_part, 1, 'e');
	else
		second_part = ft_join_char(second_part, 1, 'E');
	return (second_part);
}

char	*ft_do_exponent_string(long double nbr, t_arg *func, int exponent)
{
	char	*first_part;
	char	*second_part;
	char	*tmp;
	int		k;

	first_part = NULL;
	k = exponent;
	if (exponent < 0)
		k = -exponent;
	second_part = ft_itoa_base(k, 10);
	second_part = ft_sec_part_exp(second_part, func, exponent);
	first_part = ft_print_float(first_part, func, nbr);
	if (func->chr == 'G' || func->chr == 'g')
		first_part = ft_del_zero(first_part, func);
	tmp = first_part;
	first_part = ft_strjoin(first_part, second_part);
	free(tmp);
	free(second_part);
	return (first_part);
}

char	*ft_print_exponent_double(char *string, t_arg *func, long double nbr)
{
	unsigned long long	base;
	int					exponent;

	exponent = 0;
	nbr = ft_parsing_znak_double(nbr, func);
	base = (unsigned long long)nbr;
	while (nbr != 0 && base == 0)
	{
		exponent--;
		nbr = nbr * 10;
		base = (unsigned long long)nbr;
	}
	while (base > 9)
	{
		exponent++;
		nbr = nbr / 10;
		base = (unsigned long long)nbr;
	}
	if (func->chr == 'G' || func->chr == 'g')
		return (ft_check_g(exponent, string, func, nbr));
	string = ft_do_exponent_string(nbr, func, exponent);
	return (string);
}
