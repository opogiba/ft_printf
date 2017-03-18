/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:26:34 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 20:29:26 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_handle_specifier(t_format *form, t_arg *func, va_list args)
{
	if (func->chr == 'i' || func->chr == 'd' || func->chr == 'D' ||
			func->chr == 'u' || func->chr == 'U' || func->chr == 'x' ||
			func->chr == 'X' || func->chr == 'o' || func->chr == 'O' ||
			func->chr == 'b')
		ft_print_int(form, func, args);
	else if (func->chr == 's' || func->chr == 'S')
		ft_print_string(form, func, args);
	else if (func->chr == 'p')
		ft_print_memory(form, func, args);
	else if (func->chr == 'f' || func->chr == 'F')
		ft_print_double(form, func, args);
	else if (func->chr == 'k')
		ft_print_time(form, func, args);
	else if (func->chr == 'r')
		ft_print_non_printable(form, func, args);
	else if (func->chr == 'n')
		ft_pointer_to_int(form, args);
	else if (func->chr == 'f' || func->chr == 'F' || func->chr == 'e'
			|| func->chr == 'E' || func->chr == 'g' || func->chr == 'G'
			|| func->chr == 'a' || func->chr == 'A')
		ft_print_double(form, func, args);
	else
		ft_print_char(form, func, args);
}
