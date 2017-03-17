/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_accuracy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:16:55 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/15 19:17:58 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parsing_accuracy(t_format *form, t_arg *func, va_list args)
{
	if (form->str[form->inx] == '.')
	{
		func->acc_ex = 1;
		func->acc = 0;
		form->inx++;
		if (ft_isdigit(form->str[form->inx]))
		{
			while (ft_isdigit(form->str[form->inx]))
			{
				func->acc = func->acc * 10 + (form->str[form->inx] - '0');
				form->inx++;
			}
		}
		else if (form->str[form->inx] == '*')
		{
			func->acc_ex = 1;
			func->acc = va_arg(args, int);
			if (func->acc < 0)
			{
				func->acc = 0;
				func->acc_ex = 0;
			}
			form->inx++;
		}
	}
}
