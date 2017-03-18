#include "../../ft_printf.h"

int		ft_nbr_len(unsigned long long i, unsigned long long base)
{
	int c;

	c = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / base;
		c++;
	}
	return (c);
}
