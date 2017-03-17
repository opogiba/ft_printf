/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:15:31 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/15 19:15:50 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parsing_width(t_format *form, t_arg *func, va_list args)
{
	if (ft_isdigit(form->str[form->inx]))
	{
		func->width_ex = 1;
		func->width = 0;
		while (ft_isdigit(form->str[form->inx]))
		{
			func->width = func->width * 10 + (form->str[form->inx] - '0');
			form->inx++;
		}
	}
	else if (form->str[form->inx] == '*')
	{
		func->width_ex = 1;
		func->width = va_arg(args, int);
		if (func->width < 0)
			func->f_minus = 1;
		func->width = ft_abs(func->width);
		form->inx++;
	}
}
