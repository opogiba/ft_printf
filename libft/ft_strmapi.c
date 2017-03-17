/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:31:33 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/01 22:31:35 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				array[i] = f((unsigned int)i, s[i]);
				i++;
			}
			array[i] = '\0';
			return (array);
		}
	}
	return (NULL);
}
