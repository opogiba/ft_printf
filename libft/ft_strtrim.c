/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 00:05:18 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/03 20:55:25 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (len > 0)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			len--;
			i++;
		}
	}
	if (len == 0)
		return (NULL);
	return (ft_strsub(s, i, (len + 1)));
}
