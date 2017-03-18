/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_symbols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:18:32 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:18:39 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_join_symbols(t_arg *func, char *str, int i, char c)
{
	char	*zero;
	char	*tmp;
	int		j;

	j = 0;
	if (i <= 0)
		return (str);
	tmp = str;
	zero = (char*)malloc(sizeof(char) * i + 1);
	while (i != 0)
	{
		zero[j] = c;
		j++;
		i--;
	}
	zero[j] = '\0';
	if (func->f_minus == 1 && c != '0' && c != 'x' && c != 'X')
		str = ft_strjoin(str, zero);
	else
		str = ft_strjoin(zero, str);
	free(tmp);
	free(zero);
	return (str);
}
