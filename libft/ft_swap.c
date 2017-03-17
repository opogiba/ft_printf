/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:15:07 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/06 20:15:09 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_swap(void *a, void *b)
{
	unsigned char tpm;

	tpm = *(unsigned char*)a;
	*(unsigned char*)a = *(unsigned char*)b;
	*(unsigned char*)b = tpm;
}
