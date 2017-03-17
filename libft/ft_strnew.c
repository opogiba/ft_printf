/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:25:45 by opogiba           #+#    #+#             */
/*   Updated: 2016/11/30 23:46:25 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char*)malloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);
	while (i < size)
	{
		a[i] = '\0';
		i++;
	}
	a[i] = '\0';
	return (a);
}
