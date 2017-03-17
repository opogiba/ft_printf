/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:44:26 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:44:29 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ft_clean(t_arg *func)
{
	func->acc_ex = 0;
	func->width_ex = 0;
	func->f_hash = 0;
	func->f_zero = 0;
	func->f_minus = 0;
	func->f_plus = 0;
	func->f_space = 0;
	func->f_apos = 0;
	func->width = 0;
	func->acc = 0;
	func->chr = '\0';
	func->base = 10;
	func->len = N;
	func->f_dol_val = 0;
	func->f_dollar = 0;
	func->doub_len = 0;
}
