/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:27:43 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:34:37 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	**ft_fd_mas(void)
{
	char **fd_mas;

	fd_mas = (char**)malloc(sizeof(char*) * 2);
	fd_mas[0] = ft_strdup("{fd}");
	fd_mas[1] = ft_strdup("{fdf}");
	return (fd_mas);
}

int		ft_check(int k, va_list args, t_format *form, char **fd_mas)
{
	if (k == (int)(ft_strlen(fd_mas[0])))
	{
		form->fd = va_arg(args, int);
		return (1);
	}
	if (k == (int)(ft_strlen(fd_mas[1])))
	{
		form->fd = 1;
		return (1);
	}
	return (0);
}

int		ft_choose_fd(char **fd_mas, t_format *form, va_list args)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	i = form->inx;
	while (fd_mas[j])
	{
		while (fd_mas[j][k] == form->str[i])
		{
			i++;
			k++;
		}
		if (ft_check(k, args, form, fd_mas) == 1)
			return (k);
		i = form->inx;
		k = 0;
		j++;
	}
	return (0);
}
