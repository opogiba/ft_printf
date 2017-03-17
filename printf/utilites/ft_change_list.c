/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:25:54 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:26:19 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_change_list(va_list args, va_list tmp, t_arg *func)
{
	va_copy(args, tmp);
	while (--func->f_dol_val)
		va_arg(args, int);
}
