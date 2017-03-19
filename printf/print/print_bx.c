/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:40:38 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/19 20:43:33 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

//static char	*ft_prefix_width(t_arg *func, char *str)
//{
//	if (func->chr == 'X')
//		str = ft_join_symbols(func, str, 1, 'X');
//	else if (func->chr == 'x')
//		str = ft_join_symbols(func, str, 1, 'x');
//	else if (func->chr == 'b')
//		str = ft_join_symbols(func, str, 1, 'b');
//	str = ft_join_symbols(func, str, 1, '0');
//	return (str);
//}

//char		*ft_print_bx(char *str, int minus, t_arg *func)
//{
//	char	*first_part;
//	int		i;
//
//	first_part = ft_strdup("");
//	if (func->f_hash == 1)
//		first_part = ft_prefix_width(func, first_part);
//	i = func->width - (int)ft_strlen(first_part) - (int)ft_strlen(str);
//	if (func->f_zero == 1)
//	{
//		if (func->f_plus == 1 || func->f_space == 1)
//			str = ft_join_symbols(func, str, i - 1, '0');
//		else
//			str = ft_join_symbols(func, str, i, '0');
//	}
//	else
//		str = ft_join_symbols(func, str, i, ' ');
//	if (func->f_plus == 1 || func->f_space == 1)
//		first_part = ft_join_prefix(first_part, func, minus, 0);
//	str = ft_strjoin(first_part, str);
//	free(first_part);
//	return (str);
//}
//static char	*ft_prefix_width(t_arg *func, char *str)
//{
//	if (func->f_hash == 1 &&
//			(func->chr == 'X' || func->chr == 'x' || func->chr == 'b'))
//	{
//		if (func->chr == 'X')
//			str = ft_join_symbols(func, str, 1, 'X');
//		if (func->chr == 'x')
//			str = ft_join_symbols(func, str, 1, 'x');
//		if (func->chr == 'b')
//			str = ft_join_symbols(func, str, 1, 'b');
//		str = ft_join_symbols(func, str, 1, '0');
//	}
//	return (str);
//}
//
//char		*ft_width_int(t_arg *func, char *str, int minus, int i)
//{
//	if (func->f_zero == 1)
//	{
//		if ((func->chr == 'X' || func->chr == 'x' || func->chr == 'b')
//			&& func->f_hash == 1)
//		{
//			str = ft_join_symbols(func, str,
//								   +					func->width - (int)ft_strlen(str) - 2, '0');
//		}
//		else
//		{
//			str = ft_join_symbols(func, str,
//								   +					func->width - (int)ft_strlen(str), '0');
//		}
//		if (i >= func->width && (func->f_plus == 1 || func->f_space == 1))
//			str = ft_join_prefix(str, func, minus, 0);
//		else
//			str = ft_join_prefix(str, func, minus, 1);
//	}
//	str = ft_prefix_width(func, str);
//	if (func->f_zero == 1)
//		return (str);
//	if (func->f_plus == 1 || func->f_space == 1)
//		str = ft_join_prefix(str, func, minus, 0);
//	str = ft_join_symbols(func, str, func->width - (int)ft_strlen(str), ' ');
//	return (str);