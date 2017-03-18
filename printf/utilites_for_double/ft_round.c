/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 04:41:22 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/18 04:43:30 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char		*ft_round(long double nbr, t_arg *func, char *str)
{
	int	i;
	int	acc;
	int	j;

	j = 0;
	acc = func->acc;
	while (acc > 0)
	{
		nbr *= 10;
		if (acc == 1)
			nbr = ft_r_nbr(nbr);
		i = (int)nbr;
		str[j] = (char)(i + '0');
		nbr = nbr - i;
		acc--;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_round_d(long double nbr, t_arg *func, char *str)
{
	int			p;
	long long	nbr_l;
	int			i;
	char		*string;
	char		*tmp;

	i = 0;
	p = func->acc;
	while (p > 0 && p-- > 0)
		nbr *= 10;
	nbr_l = ft_r_nbr(nbr);
	p = func->acc - ft_nbr_len(nbr_l, 10);
	while (p > 0)
	{
		str[i++] = '0';
		p--;
	}
	str[i] = '\0';
	tmp = str;
	string = ft_itoa_base(nbr_l, 10);
	str = ft_strjoin(str, string);
	free(tmp);
	free(string);
	return (str);
}
