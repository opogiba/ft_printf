/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:45:02 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 13:48:41 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	ft_parse_string(t_arg *func)
{
	if (func->chr == 'S')
		func->len = L;
	if (!func->acc_ex)
		func->acc = -1;
	if (func->f_minus == 1)
		func->f_zero = 0;
}

static char	*ft_print_wstring(wchar_t *string, int len)
{
	char	*wint_tmp;
	char	*tmp;
	char	*str;
	size_t	size;

	if (!string)
		return (ft_strdup("(null)"));
	size = 0;
	str = ft_strdup("");
	while (string[size])
	{
		tmp = str;
		wint_tmp = ft_wchar_to_int(string[size]);
		str = ft_strjoin(str, wint_tmp);
		free(wint_tmp);
		if (len >= 0 && (int)ft_strlen(str) > len)
		{
			free(str);
			str = tmp;
			break ;
		}
		free(tmp);
		size++;
	}
	return (str);
}

char		*ft_accuracy_string(t_arg *func, char *string)
{
	char *tmp;

	tmp = NULL;
	if (func->acc_ex == 1 && *string != '\0')
	{
		if ((int)ft_strlen(string) > func->acc)
		{
			tmp = string;
			string = ft_strsub(string, 0, func->acc);
			free(tmp);
		}
	}
	return (string);
}

void		ft_print_string(t_format *form, t_arg *func, va_list args)
{
	char *string;

	ft_parse_string(func);
	if (func->len == L)
		string = ft_print_wstring(va_arg(args, wchar_t*), func->acc);
	else
	{
		string = va_arg(args, char*);
		if (string == NULL)
			string = ft_strdup("(null)");
		else
			string = ft_strdup(string);
	}
	string = ft_accuracy_string(func, string);
	if (func->f_zero == 1 && func->acc <= 0)
		string = ft_join_symbols(func, string,
				func->width - (int)ft_strlen(string), '0');
	else
		string = ft_join_symbols(func, string,
				func->width - (int)ft_strlen(string), ' ');
	ft_print(string, form);
	free(string);
}
