/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:35:51 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:37:43 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_join_symbol(t_arg *func, char a, t_format *form, char b)
{
	char	*zero;
	int		i;
	int		j;

	i = func->width - 1;
	j = 0;
	zero = (char*)malloc(sizeof(char) * i);
	while (i > 0)
	{
		zero[j++] = b;
		i--;
	}
	zero[j] = '\0';
	if (func->f_minus == 0)
	{
		ft_print(zero, form);
		write(form->fd, &a, 1);
	}
	else
	{
		write(form->fd, &a, 1);
		ft_print(zero, form);
	}
	form->format_written++;
	free(zero);
}
