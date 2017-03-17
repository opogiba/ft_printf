/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_apostrophe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:40:19 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/17 16:25:05 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*ft_apostrophe(char *string, int exponent, int len, int amount)
{
	char	*tmp;
	int		fraction;
	int		diff;
	int		i;

	i = 0;
	diff = len + amount;
	fraction = len - exponent;
	tmp = (char*)malloc(sizeof(char) * len + amount + 1);
	tmp[diff--] = '\0';
	len--;
	while (fraction--)
		tmp[diff--] = string[len--];
	while (diff >= 0)
	{
		if ((i + 1) % 4 == 0 && diff != 0)
		{
			tmp[diff--] = ',';
			i++;
		}
		tmp[diff--] = string[len--];
		i++;
	}
	free(string);
	return (tmp);
}

char		*ft_put_apostrophe(char *string, t_arg *func)
{
	int exponent;
	int len;
	int amount;

	if (func->chr == 'i' || func->chr == 'd' || func->chr == 'D' ||
			func->chr == 'u' || func->chr == 'U' || func->chr == 'f' ||
			func->chr == 'F')
	{
		exponent = 0;
		len = (int)ft_strlen(string);
		while (ft_isdigit(string[exponent]))
			exponent++;
		amount = (exponent - 1) / 3;
		string = ft_apostrophe(string, exponent, len, amount);
		return (string);
	}
	return (string);
}
