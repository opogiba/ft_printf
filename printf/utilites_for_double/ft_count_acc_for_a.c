/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_acc_for_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 20:28:24 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 20:28:53 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_count_acc_for_a(long double nbr)
{
	int i;
	int base;

	i = 0;
	while (nbr != 0)
	{
		nbr = nbr * 16;
		base = (int)nbr;
		nbr -= (long double)base;
		i++;
	}
	return (i);
}
