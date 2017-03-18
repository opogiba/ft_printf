/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 05:18:48 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 05:18:49 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_nbr_len(unsigned long long i, unsigned long long base)
{
	int c;

	c = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / base;
		c++;
	}
	return (c);
}
