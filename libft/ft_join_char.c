/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 20:36:35 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/19 20:36:44 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_join_char(char *str, int flag, char c)
{
	char	*zero;
	char	*tmp;

	zero = ft_strdup(" ");
	zero[0] = c;
	tmp = str;
	if (flag == 0)
	{
		str = ft_strjoin(str, zero);
	}
	else
		str = ft_strjoin(zero, str);
	free(tmp);
	free(zero);
	return (str);
}
