/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:39:23 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:40:02 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_join_prefix(char *str, t_arg *func, int minus, int flag)
{
	char *tmp;

	if (flag == 1)
	{
		if (minus == -1 && func->f_plus == 1)
			str[0] = '-';
		if (func->f_space == 1 && minus == 1)
			str[0] = ' ';
		if (minus == 1 && func->f_plus == 1)
			str[0] = '+';
		return (str);
	}
	tmp = str;
	if (func->f_space == 1 && minus == 1)
		str = ft_strjoin(" ", str);
	if (minus == 1 && func->f_plus == 1)
		str = ft_strjoin("+", str);
	if (minus == -1 && func->f_plus == 1)
		str = ft_strjoin("-", str);
	free(tmp);
	return (str);
}
