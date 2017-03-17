/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_to_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:23:38 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:24:11 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_pointer_to_int(t_format *form, va_list args)
{
	int *i;

	i = va_arg(args, int*);
	if (!i && !*i)
		return ;
	else
		*i = form->format_written;
}
