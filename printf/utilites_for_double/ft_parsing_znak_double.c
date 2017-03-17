#include "../../ft_printf.h"

long double	ft_parsing_znak_double(long double nbr, t_arg *func)
{
	if(nbr < 0)
	{
		func->f_plus = 1;
		nbr = -nbr;
	}
	if (func->f_plus == 1)
		func->f_space = 0;
	if (func->f_minus == 1)
		func->f_zero = 0;
	return (nbr);
}