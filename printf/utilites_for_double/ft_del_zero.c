/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_g.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 04:47:01 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 04:48:50 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_del_zero(char *string, t_arg *func)
{
	int		len;
	char	a;

	a = '.';
	len = (int)ft_strlen(string);
	if (ft_strchr(string, a) && func->f_hash == 0)
	{
		len = len - 1;
		while (string[len] == '0')
		{
			string[len--] = '\0';
		}
		if (string[len] == '.')
			string[len] = '\0';
	}
	return (string);
}


