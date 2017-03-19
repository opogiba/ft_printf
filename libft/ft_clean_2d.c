/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:35:35 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/19 20:35:49 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_clean_2dchar(char **nbr)
{
	int i;

	i = 0;
	while (nbr[i])
	{
		free(nbr[i]);
		i++;
	}
	free(nbr);
	nbr = NULL;
}
