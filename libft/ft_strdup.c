/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:17:00 by opogiba           #+#    #+#             */
/*   Updated: 2016/11/29 21:17:04 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_strcpy(dest, s1);
	return (dest);
}
