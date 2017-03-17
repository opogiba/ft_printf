/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nonprintable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:32:10 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/17 16:36:46 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	ft_check_tab(char a, t_format *form)
{
	if (a == '\n')
		write(form->fd, "\\n", 2);
	if (a == '\t')
		write(form->fd, "\\t", 2);
	if (a == '\v')
		write(form->fd, "\\v", 2);
	if (a == '\f')
		write(form->fd, "\\f", 2);
	if (a == '\r')
		write(form->fd, "\\r", 2);
}

static void	ft_print_non(char *str, t_format *form, t_arg *func)
{
	int		i;
	char	*a;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			write(form->fd, &str[i], 1);
		else if ((str[i] == '\t') || (str[i] == '\n')
				|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
			ft_check_tab(str[i], form);
		else
		{
			a = ft_utoa_base(str[i], 16, func);
			write(form->fd, &a, ft_strlen(a));
			free(a);
		}
		form->format_written++;
		i++;
	}
}

void		ft_print_non_printable(t_format *form, t_arg *func, va_list args)
{
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str = ft_accuracy_string(func, str);
	if (func->f_zero == 1 && func->acc <= 0)
		str = ft_join_symbols(func, str,
				func->width - (int)ft_strlen(str), '0');
	else
		str = ft_join_symbols(func, str,
				func->width - (int)ft_strlen(str), ' ');
	ft_print_non(str, form, func);
	free(str);
}
