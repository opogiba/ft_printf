/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_brace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:32:35 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 13:32:42 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parsing_color(t_format *form)
{
	char	**color;
	char	**print_color;
	int		i;

	color = ft_choose_color();
	print_color = ft_print_color();
	i = ft_compare_color(color, print_color, form);
	ft_clean_2dchar(color);
	ft_clean_2dchar(print_color);
	if (i > 0)
		form->inx += i;
}

void	ft_parsing_fd(t_format *form, va_list args)
{
	char	**fd_mas;
	int		i;

	fd_mas = ft_fd_mas();
	i = ft_choose_fd(fd_mas, form, args);
	ft_clean_2dchar(fd_mas);
	if (i > 0)
		form->inx += i;
}

void	ft_parsing_brace(t_format *form, va_list args)
{
	if (form->str[form->inx + 1] == 'f')
		ft_parsing_fd(form, args);
	else
		ft_parsing_color(form);
}
