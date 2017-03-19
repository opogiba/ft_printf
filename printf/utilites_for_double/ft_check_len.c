/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:19:54 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:20:03 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_check_len(int len, char *finish)
{
	int i;

	i = 0;
	while (ft_isdigit(finish[i]))
		i++;
	while (i < len)
	{
		finish[i] = '0';
		i++;
	}
	return (finish);
}


