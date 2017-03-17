/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:58:11 by opogiba           #+#    #+#             */
/*   Updated: 2016/11/29 17:58:13 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*s;

	p = dst;
	s = src;
	if (p > s)
	{
		i = len;
		while (i)
		{
			p[i - 1] = s[i - 1];
			i--;
		}
	}
	else if (p < s)
	{
		i = 0;
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
	}
	return (dst);
}
