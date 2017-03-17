/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:39:56 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 13:40:57 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_print_memory(t_format *form, t_arg *func, va_list args)
{
	char				*string;
	unsigned long long	nbr;

	func->chr = 'x';
	func->f_plus = 0;
	func->f_space = 0;
	nbr = (unsigned long long)va_arg(args, void*);
	ft_parsing_base(func);
	string = ft_utoa_base(nbr, func->base, func);
	string = ft_accuracy_int(func, string, nbr);
	func->f_hash = 1;
	string = ft_width_int(func, string, 1, (int)ft_strlen(string));
	ft_print(string, form);
}
