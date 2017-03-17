/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:30:13 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/17 16:31:19 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_get_double(char *string, t_arg *func, va_list args)
{
	long double	nbr;
	int			minus;

	if (func->doub_len == 1)
		nbr = (long double)va_arg(args, long double);
	else
		nbr = (double)va_arg(args, double);
	if ((string = ft_check_inf(nbr, func)) != NULL)
		return (string);
	minus = nbr < 0 ? -1 : 1;
	if (func->chr == 'f' || func->chr == 'F')
		string = ft_print_float(string, func, nbr);
	else if (func->chr == 'e' || func->chr == 'E')
		string = ft_print_exponent_double(string, func, nbr);
	else if (func->chr == 'g' || func->chr == 'G')
		string = ft_print_float_or_exponent(string, func, nbr);
	if (func->f_plus == 1 || func->f_space == 1)
		string = ft_join_prefix(string, func, minus, 0);
	return (string);
}

void	ft_print_double(t_format *form, t_arg *func, va_list args)
{
	char *string;

	string = NULL;
	if (func->acc_ex != 1)
	{
		func->acc = 6;
		func->acc_ex = 1;
	}
	if (func->chr == 'F')
		func->doub_len = 1;
	string = ft_get_double(string, func, args);
	if (func->f_apos == 1)
		string = ft_put_apostrophe(string, func);
	ft_print(string, form);
	free(string);
}
