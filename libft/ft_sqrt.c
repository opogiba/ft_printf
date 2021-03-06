/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:19:02 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/06 21:17:05 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
	{
		i++;
	}
	if (i * i == nb)
		return (i);
	else
		return (0);
}
