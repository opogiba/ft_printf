/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:19:47 by opogiba           #+#    #+#             */
/*   Updated: 2016/11/30 21:15:06 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			a = &s[i];
		i++;
	}
	if ((char)c != '\0' && a != 0)
		return ((char*)a);
	if (s[i] == (char)c)
		return ((char*)&s[i]);
	return (NULL);
}
