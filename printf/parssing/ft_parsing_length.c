/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:11:19 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/17 16:24:10 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_parsing_length(t_format *fr, t_arg *func)
{
	if (fr->str[fr->inx] == 'h' || fr->str[fr->inx] == 'l' ||
			fr->str[fr->inx] == 'L' || fr->str[fr->inx] == 'j' ||
			fr->str[fr->inx] == 'z')
	{
		if (fr->str[fr->inx] == 'h' && fr->str[fr->inx + 1] == 'h')
			func->len = func->len < HH ? HH : func->len;
		else if (fr->str[fr->inx] == 'l' && fr->str[fr->inx + 1] == 'l')
			func->len = func->len < LL ? LL : func->len;
		else if (fr->str[fr->inx] == 'h')
			func->len = func->len < H ? H : func->len;
		else if (fr->str[fr->inx] == 'l')
			func->len = func->len < L ? L : func->len;
		else if (fr->str[fr->inx] == 'j')
			func->len = func->len < J ? J : func->len;
		else if (fr->str[fr->inx] == 'z')
			func->len = func->len < Z ? Z : func->len;
		else if (fr->str[fr->inx] == 'L')
			func->doub_len = 1;
		if ((fr->str[fr->inx] == 'h' && fr->str[fr->inx + 1] == 'h') ||
				(fr->str[fr->inx] == 'l' && fr->str[fr->inx + 1] == 'l'))
			fr->inx += 2;
		else
			fr->inx++;
	}
}
