/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cust_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:37:31 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:30:46 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

unsigned long long	ft_cust_uxo(t_arg *func, va_list args)
{
	unsigned long long	nbr;

	if (func->len == L)
		nbr = va_arg(args, unsigned long int);
	else if (func->len == LL)
		nbr = va_arg(args, unsigned long long);
	else if (func->len == H)
		nbr = (unsigned short)va_arg(args, unsigned int);
	else if (func->len == HH)
		nbr = (unsigned char)va_arg(args, unsigned int);
	else if (func->len == J)
		nbr = va_arg(args, uintmax_t);
	else if (func->len == Z)
		nbr = va_arg(args, size_t);
	else
		nbr = va_arg(args, unsigned int);
	return (nbr);
}

long long			ft_cust_id(t_arg *func, va_list args)
{
	long long nbr;

	if (func->len == L)
		nbr = va_arg(args, long int);
	else if (func->len == LL)
		nbr = va_arg(args, long long);
	else if (func->len == H)
		nbr = (short)va_arg(args, int);
	else if (func->len == HH)
		nbr = (char)va_arg(args, int);
	else if (func->len == J)
		nbr = va_arg(args, intmax_t);
	else if (func->len == Z)
		nbr = va_arg(args, size_t);
	else
		nbr = va_arg(args, int);
	return (nbr);
}
