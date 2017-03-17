/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:47:58 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 13:31:32 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parsing(t_format *form, t_arg *func, va_list args)
{
	int i;

	i = 0;
	while (ft_strchr("#+-0123456789 '$hlLjz*.", form->str[form->inx]) &&
			form->str[form->inx])
	{
		ft_parsing_flags(form, func, i);
		ft_parsing_width(form, func, args);
		ft_parsing_accuracy(form, func, args);
		ft_parsing_length(form, func);
		i = 1;
	}
	func->chr = form->str[form->inx];
}
