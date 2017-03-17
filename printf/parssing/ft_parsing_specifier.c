/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:13:46 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/15 19:14:58 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parsing_specifier(t_arg *func, unsigned long long nbr)
{
	if (func->chr == 'u' || func->chr == 'U' || func->chr == 'x' ||
		func->chr == 'X' || func->chr == 'o' || func->chr == 'O')
	{
		func->f_plus = 0;
		func->f_space = 0;
	}
	if ((func->chr == 'x' || func->chr == 'X') && nbr == 0)
		func->f_hash = 0;
	if (func->chr == 'C')
	{
		func->len = L;
		func->chr = 'c';
	}
	if (func->f_plus == 1)
		func->f_space = 0;
	if (func->f_minus == 1 || func->acc_ex == 1)
		func->f_zero = 0;
}

void	ft_parsing_base(t_arg *func)
{
	if (func->chr == 'o' || func->chr == 'O')
		func->base = 8;
	if (func->chr == 'x' || func->chr == 'X')
		func->base = 16;
	if (func->chr == 'b')
		func->base = 2;
}
