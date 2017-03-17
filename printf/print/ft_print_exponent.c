/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exponent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:32:47 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/17 16:36:26 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_sec_part_exp(char *second_part, t_arg *func, int count)
{
	if (count > -10 && count < 10)
		second_part = ft_join_char(second_part, 1, '0');
	if (count < 0)
		second_part = ft_join_char(second_part, 1, '-');
	else
		second_part = ft_join_char(second_part, 1, '+');
	if (func->chr >= 97 && func->chr <= 122)
		second_part = ft_join_char(second_part, 1, 'e');
	else
		second_part = ft_join_char(second_part, 1, 'E');
	return (second_part);
}

char	*ft_do_exponent_string(long double nbr, t_arg *func, int count)
{
	char	*finish;
	char	*second_part;
	char	*tmp;
	int		k;

	finish = NULL;
	k = count;
	if (count < 0)
		k = -count;
	second_part = ft_itoa_base(k, 10);
	second_part = ft_sec_part_exp(second_part, func, count);
	finish = ft_print_float(finish, func, nbr);
//	if ((func->chr == 'G' || func->chr == 'g') && func->f_hash == 0)
//	{
//		k = (int)ft_strlen(finish);
//		k = k - 1;
//		while (finish[k] == '0')
//			finish[k--] = '\0';
//		if (finish[k] == '.')
//			finish[k] = '\0';
//	}
	tmp = finish;
	finish = ft_strjoin(finish, second_part);
	free(tmp);
	free(second_part);
	return (finish);
}

char	*ft_print_exponent_double(char *string, t_arg *func, long double nbr)
{
	unsigned long long	exponent;
	int					count;

	count = 0;
	nbr = ft_parsing_znak_double(nbr, func);
	exponent = (unsigned long long)nbr;
	while (nbr != 0 && exponent == 0)
	{
		count--;
		nbr = nbr * 10;
		exponent = (unsigned long long)nbr;
	}
	while (exponent > 9)
	{
		count++;
		nbr = nbr / 10;
		exponent = (unsigned long long)nbr;
	}
//	if (func->acc_ex == 1 && func->acc == 0)
//		nbr = ft_r_nbr(nbr);
//	if (func->chr == 'G' || func->chr == 'g')
//		return (ft_check_g(count, string, func, nbr));
	string = ft_do_exponent_string(nbr, func, count);
	return (string);
}

//	if (func->acc_ex == 1 && func->acc == 0)
//		nbr = ft_r_nbr(nbr);
//	if (func->chr == 'G' || func->chr == 'g')
//	{
//		if((count < -4  || (count >= func->acc)) && func->base == 10)
//		{
//			string = ft_do_exponent_string(nbr, func, count);
//			return (string);
//		}
//		else
//			return (NULL);
