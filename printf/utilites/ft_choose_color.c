/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:27:15 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:34:03 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	**ft_choose_color(void)
{
	char **color_mas;

	color_mas = (char**)malloc(sizeof(char*) * 10);
	color_mas[0] = ft_strdup("{red}");
	color_mas[1] = ft_strdup("{green}");
	color_mas[2] = ft_strdup("{yellow}");
	color_mas[3] = ft_strdup("{blue}");
	color_mas[4] = ft_strdup("{magenta}");
	color_mas[5] = ft_strdup("{cyan}");
	color_mas[6] = ft_strdup("{white}");
	color_mas[7] = ft_strdup("{black}");
	color_mas[8] = ft_strdup("{eoc}");
	color_mas[9] = NULL;
	return (color_mas);
}

char	**ft_print_color(void)
{
	char **color_mas;

	color_mas = (char**)malloc(sizeof(char*) * 10);
	color_mas[0] = ft_strdup("\x1B[31m\0");
	color_mas[1] = ft_strdup("\x1B[32m\0");
	color_mas[2] = ft_strdup("\x1B[33m\0");
	color_mas[3] = ft_strdup("\x1B[34m\0");
	color_mas[4] = ft_strdup("\x1B[35m\0");
	color_mas[5] = ft_strdup("\x1B[36m\0");
	color_mas[6] = ft_strdup("\x1B[37m\0");
	color_mas[7] = ft_strdup("\x1B[30m\0");
	color_mas[8] = ft_strdup("\x1B[0m\0");
	color_mas[9] = NULL;
	return (color_mas);
}

int		ft_compare_color(char **color, char **print_color, t_format *form)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	i = form->inx;
	while (color[j])
	{
		while (color[j][k] == form->str[i])
		{
			i++;
			k++;
		}
		if ((int)ft_strlen(color[j]) == k)
		{
			ft_putstr(print_color[j]);
			return (k);
		}
		i = form->inx;
		k = 0;
		j++;
	}
	return (0);
}
