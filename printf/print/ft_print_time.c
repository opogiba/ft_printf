/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:50:46 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 13:51:25 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_print_time(t_format *form, t_arg *func, va_list args)
{
	char	*tmp;
	t_time	*tm;
	char	*string;
	int		i;

	tm = (t_time*)malloc(sizeof(t_time));
	ft_convert_time(tm, va_arg(args, unsigned long long));
	i = 0;
	string = ft_utoa_base(tm->year, 10, func);
	while (i < 6)
	{
		string = i == 1 ? ft_utoa_base(tm->month, 10, func) : string;
		string = i == 2 ? ft_utoa_base(tm->day, 10, func) : string;
		string = i == 3 ? ft_utoa_base(tm->hour, 10, func) : string;
		string = i == 4 ? ft_utoa_base(tm->min, 10, func) : string;
		string = i == 5 ? ft_utoa_base(tm->sec, 10, func) : string;
		tmp = string;
		ft_print(string, form);
		if (i != 5)
			ft_print("-", form);
		free(tmp);
		i++;
	}
	free(string);
	free(tm);
}
