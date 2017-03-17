/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:41:58 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/06 20:42:44 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrev(char *str)
{
	int		counter;
	int		size_str;
	char	temp;

	counter = 0;
	size_str = 0;
	while (str[size_str])
		size_str++;
	size_str -= 1;
	while (counter < size_str)
	{
		temp = str[size_str];
		str[size_str] = str[counter];
		str[counter] = temp;
		counter++;
		size_str--;
	}
	return (str);
}
