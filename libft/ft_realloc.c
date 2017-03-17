/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:14:39 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/06 21:14:44 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void *old, unsigned int new_size, unsigned int old_size)
{
	void	*new;

	new = ft_memalloc(new_size);
	ft_memcpy(new, old, old_size);
	free(old);
	return (new);
}
