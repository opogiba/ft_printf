/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:44:00 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:45:17 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_utoa_base(unsigned long long value, int b, t_arg *func)
{
	char				*base;
	char				*result;
	unsigned long long	v;
	unsigned long long	tmp;
	int					len;

	len = 1;
	if (func->chr == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	v = value;
	tmp = value;
	while ((tmp /= b))
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len--)
	{
		result[len] = base[v % b];
		v /= b;
	}
	return (result);
}
