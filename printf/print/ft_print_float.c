/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:36:59 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/17 16:37:17 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	nbr_to_str(unsigned long long value, unsigned long long base,
				   char **str)
{
	char	c;

	if (value >= base)
	{
		nbr_to_str(value / base, base, str);
		nbr_to_str(value % base, base, str);
	}
	else
	{

		c = value + '0';
		**str = c;
		(*str)++;
	}
	**str = '\0';
}
void		add_dot(char **str)
{


		**str = '.';
		(*str)++;

}

char	*ft_print_float(char *string, t_arg *func, long double nbr)
{
	long long	exponenta;
	char *finish;
	char *tmp;

	nbr = ft_parsing_znak_double(nbr, func);
	if (func->acc_ex == 1 && func->acc == 0)
		nbr = ft_r_nbr(nbr);
	exponenta = (long long)nbr;

	string = ft_itoa_base(exponenta, 10);
	finish = (char *) malloc(sizeof(char) * (func->acc + exponenta) + 1);
//	finish[func->acc] = '\0';
//	nbr_to_str(exponenta, 10, &finish);
//	add_dot(&finish);


	if(func->acc > 0 && func->acc <= 15)
		ft_round_d(nbr - (long double)exponenta, func, finish);
	else if(func->acc == 0 || func->acc > 15)
		ft_round(nbr - (long double)exponenta, func, finish);
//	if((int)ft_strlen(finish) != func->acc)
//		ft_check_len((int)ft_strlen(finish), func->acc, finish);
//	string = ft_dot_to_float(string, func);
//	tmp = finish;
	finish = ft_strjoin(string, finish);
//	free(string);
//	free(tmp);
	return (finish);
}











//
//char	*ft_print_float(char *string, t_arg *func, long double nbr)
//{
//	long long	exponenta;
//	char *finish;
//	char *tmp;
//
//	nbr = ft_parsing_znak_double(nbr, func);
//	if (func->acc_ex == 1 && func->acc == 0)
//		nbr = ft_r_nbr(nbr);
//	exponenta = (long long)nbr;
//	string = ft_itoa_base(exponenta, 10);
//	finish = (char *) malloc(sizeof(char) * func->acc + 1);
//	finish[func->acc] = '\0';
//	if(func->acc > 0 && func->acc <= 15)
//		finish = ft_round_d(nbr - (long double)exponenta, func, finish);
//	else if(func->acc == 0 || func->acc > 15)
//		finish = ft_round(nbr - (long double)exponenta, func, finish);
//	if((int)ft_strlen(finish) != func->acc)
//		ft_check_len((int)ft_strlen(finish), func->acc, finish);
//	string = ft_dot_to_float(string, func);
//	tmp = finish;
//	finish = ft_strjoin(string, finish);
//	free(string);
//	free(tmp);
//	return (finish);
//}