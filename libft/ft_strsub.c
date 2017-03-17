/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:41:46 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/03 20:56:58 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*array;

	i = 0;
	array = NULL;
	if (s)
	{
		array = (char*)malloc(sizeof(*s) * len + 1);
		if (array != NULL)
		{
			while (len)
			{
				array[i] = s[start];
				i++;
				len--;
				start++;
			}
			array[i] = '\0';
			return (array);
		}
	}
	return (NULL);
}
