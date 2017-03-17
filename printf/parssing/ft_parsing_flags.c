/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:10:30 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 13:27:32 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parsing_flags(t_format *form, t_arg *func, int i)
{
	while (form->str[form->inx])
	{
		if (form->str[form->inx] == '#')
			func->f_hash = 1;
		else if (form->str[form->inx] == '0')
			func->f_zero = 1;
		else if (form->str[form->inx] == '-')
			func->f_minus = 1;
		else if (form->str[form->inx] == '+')
			func->f_plus = 1;
		else if (form->str[form->inx] == ' ')
			func->f_space = 1;
		else if (form->str[form->inx] == '\'')
			func->f_apos = 1;
		else if (ft_isdigit(form->str[form->inx]) &&
				form->str[form->inx + 1] == '$' && i == 0)
		{
			form->inx = form->inx++;
			func->f_dollar = 1;
			func->f_dol_val = form->str[form->inx] + '0';
		}
		else
			break ;
		form->inx++;
	}
}
