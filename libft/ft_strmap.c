/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:18:24 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/03 21:00:04 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*array;

	i = 0;
	array = NULL;
	if (f && s)
	{
		array = (char*)malloc(sizeof(*s) * ft_strlen(s) + 1);
		if (array != NULL)
		{
			while (s[i])
			{
				array[i] = f(s[i]);
				i++;
			}
			array[i] = '\0';
			return (array);
		}
	}
	return (NULL);
}
