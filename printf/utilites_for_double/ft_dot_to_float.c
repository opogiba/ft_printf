/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_to_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:20:35 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:20:38 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_dot_to_float(char *string, t_arg *func)
{
	char *tmp;

	if (func->acc != 0)
	{
		tmp = string;
		string = ft_strjoin(string, ".");
		free(tmp);
	}
	else if (func->f_hash == 1)
	{
		tmp = string;
		string = ft_strjoin(string, ".");
		free(tmp);
	}
	return (string);
}
