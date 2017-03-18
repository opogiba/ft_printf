/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:53:03 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/17 16:28:47 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

void	ft_check_percent(t_format *form, t_arg *func, va_list args, va_list tmp)
{
	form->inx++;
	ft_parsing(form, func, args);
	if (form->str[form->inx] == '\0')
		return ;
	if (func->f_dollar == 1)
		ft_change_list(args, tmp, func);
	ft_handle_specifier(form, func, args);
	form->inx++;
	ft_clean(func);
}

void	ft_format(t_format *form, t_arg *func, va_list args)
{
	va_list tmp;

	va_copy(tmp, args);
	while (form->str[form->inx])
	{
		if (form->str[form->inx] == '{')
			ft_parsing_brace(form, args);
		if (form->str[form->inx] == '%')
			ft_check_percent(form, func, args, tmp);
		else if (form->str[form->inx])
		{
			ft_putchar_fd(form->str[form->inx], form->fd);
			form->format_written++;
			form->inx++;
		}
	}
	free(func);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_arg		*func;
	t_format	*form;
	int			i;

	form = (t_format *)malloc(sizeof(t_format));
	func = (t_arg *)malloc(sizeof(t_arg));
	form->fd = 1;
	form->format_written = 0;
	form->inx = 0;
	form->str = format;
	ft_clean(func);
	va_start(args, format);
	ft_format(form, func, args);
	va_end(args);
	i = form->format_written;
	free(form);
	return (i);
}

//int main()
//{
////	double a = 42.42;
////	printf("%zd%zd\n", 0, 42);
////	ft_printf("%zd%zd\n", 0, 42);
////	printf("{%F}\n", 1.42, 1.42);
////	ft_printf("{%F}\n", 1.42, 1.42);
////	printf("%#x\n", 42);
////	ft_printf("%#x\n", 42);
////	printf("% p|%+p\n", 42, 42);
////	ft_printf("% p|%+p\n", 42, 42);
//
////	ft_printf("%e\n", 0.006);
////	printf("%e\n", 0.006);
////	printf("%.8g\n",1234567.9);
////	printf("%D\n", LONG_MAX);
////	ft_printf("%D\n", LONG_MAX);
////	ft_printf("%+010f {red}dsad{eoc}dsada{green}dasdsad\n", 0.503);
////	ft_printf("%+010f", 0.503);
////	5.000000000E+02
////	printf("%.2G\n", 42.42);
////	ft_printf("%.2G\n", 42.42);
//	printf("%.6G\n", 2147483647.0);
//	ft_printf("%.6G\n", 2147483647.0);
//
//
//	return (0);
//}
