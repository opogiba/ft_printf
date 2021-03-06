/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:35:25 by opogiba           #+#    #+#             */
/*   Updated: 2016/11/29 23:35:27 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i])
	{
		s1[i + len] = s2[i];
		i++;
	}
	s1[i + len] = s2[i];
	return (s1);
}
