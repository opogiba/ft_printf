/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:31:18 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:31:22 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char		*ft_accuracy_int(t_arg *func, char *str, unsigned long long nbr)
{
	int i;

	i = func->acc - (int)ft_strlen(str);
	if (func->f_apos == 1)
		str = ft_put_apostrophe(str, func);
	if ((func->chr == 'o' || func->chr == 'O')
		&& nbr == 0 && func->acc == 0 && func->f_hash == 0 && func->acc_ex == 1)
	{
		str = ft_clean_str(str);
		return (str);
	}
	else if (func->f_hash == 1 && (func->chr == 'o' || func->chr == 'O')
			&& nbr != 0)
	{
		str = ft_join_symbols(func, str, 1, '0');
		i = func->acc - (int)ft_strlen(str);
	}
	if (func->acc_ex == 1 && i > 0)
		str = ft_join_symbols(func, str, i, '0');
	if (func->acc == 0 && nbr == 0 && func->acc_ex == 1
		&& func->chr != 'O' && func->chr != 'o')
		str = ft_clean_str(str);
	return (str);
}

char		*ft_width_int(t_arg *func, char *str, int minus, int i)
{
	if (func->chr == 'X' || func->chr == 'x' || func->chr == 'b')
	{
		str = ft_print_bx(str, minus, func);
		return (str);
	}
	if (func->f_zero == 1)
	{
		str = ft_join_symbols(func, str, func->width - i, '0');
		if (i >= func->width && (func->f_plus == 1 || func->f_space == 1))
			str = ft_join_prefix(str, func, minus, 0);
		else
			str = ft_join_prefix(str, func, minus, 1);
		return (str);
	}
	if (func->f_plus == 1 || func->f_space == 1)
		str = ft_join_prefix(str, func, minus, 0);
	str = ft_join_symbols(func, str, func->width - (int)ft_strlen(str), ' ');
	return (str);
}

void		ft_print_int(t_format *form, t_arg *func, va_list args)
{
	long long				nbr;
	char					*str;
	int						minus;
	unsigned long long		nbr2;

	minus = 1;
	nbr = 0;
	ft_parsing_base(func);
	if (func->chr == 'i' || func->chr == 'd' || func->chr == 'D')
	{
		nbr = ft_cust_id(func, args);
		if (nbr < 0)
			minus = -1;
		nbr2 = (unsigned long long)nbr * minus;
	}
	else
		nbr2 = ft_cust_uxo(func, args);
	ft_parsing_specifier(func, nbr2);
	str = ft_utoa_base(nbr2, func->base, func);
	str = ft_accuracy_int(func, str, nbr2);
	str = ft_width_int(func, str, minus, (int)ft_strlen(str));
	ft_print(str, form);
	free(str);
}
