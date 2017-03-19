/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:26:30 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:21:41 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_check_inf(long double nbr, t_arg *func)
{
	char *string;

	string = NULL;
	if (nbr != nbr)
	{
		string = func->chr >= 65 && func->chr <= 90
				 ? ft_strdup("NAN") : ft_strdup("nan");
	}
	else if (nbr == -1 / 0.0)
	{
		string = func->chr >= 65 && func->chr <= 90
				 ? ft_strdup("-INF") : ft_strdup("-inf");
	}
	else if (nbr == 1. / 0.0)
	{
		string = func->chr >= 65 && func->chr <= 90
				 ? ft_strdup("INF") : ft_strdup("inf");
//		if (func->chr >= 65 && func->chr <= 90)
//			string = ft_strdup("INF");
//		else
//			string = ft_strdup("inf");
	}
	if(string != NULL)
		func->f_zero = 0;
	return (string);
}
