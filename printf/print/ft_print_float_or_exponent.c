#include "../../ft_printf.h"

char 	*ft_print_float_or_exponent(char *string, t_arg *func, long double nbr)
{
	int len;
//	int acc;
//
//	acc = func->acc;

	string = ft_print_exponent_double(string, func, nbr);
	if(string == NULL)
	{
		len = (int)ft_strlen(ft_itoa((int)nbr));
		func->acc = func->acc - len;
		func->acc = func->acc >= 0 ? func->acc : 0;

		string = ft_print_float(string, func, nbr);
		string =ft_del_zero(string, func);
	}
	return (string);
}
