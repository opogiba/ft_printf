/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:34:50 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 13:35:51 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_print_char(t_format *form, t_arg *func, va_list args)
{
	char a;

	func->acc_ex = 0;
	ft_parsing_specifier(func, 0);
	if (func->chr != 'c')
		a = func->chr;
	if (func->chr == 'c')
	{
		if (func->len == L)
			a = (char)va_arg(args, wchar_t);
		else
			a = va_arg(args, int);
	}
	if (func->width_ex == 1 && func->width > 1)
	{
		if (func->f_zero == 1)
			ft_join_symbol(func, a, form, '0');
		else
			ft_join_symbol(func, a, form, ' ');
	}
	else
	{
		write(form->fd, &a, 1);
		form->format_written++;
	}
}
