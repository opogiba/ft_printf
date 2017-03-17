/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:39:04 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/06 20:39:05 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_params(int argc, char **argv)
{
	int		i;
	int		index;
	char	*s;

	i = 1;
	while (i < argc)
	{
		s = argv[i];
		index = 0;
		while (s[index])
		{
			ft_putchar(s[index]);
			index++;
		}
		ft_putchar('\n');
		i++;
	}
}
