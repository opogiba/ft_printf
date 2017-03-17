#include "../../ft_printf.h"

char 	*ft_print_float_or_exponent(char *string, t_arg *func, long double nbr)
{
	int len;
	int acc;

	acc = func->acc;
	len = (int)ft_strlen(ft_itoa((int)nbr));
	func->acc = func->acc - len;
	func->acc = func->acc >= 0 ? func->acc : 0;
	if(len > acc)
	{
		func->base = 11;
		string = ft_print_exponent_double(string, func, nbr);
		return (string);
	}





//	acc = func->acc;					// ego kod
//	if (func->acc < 1 && func->acc_ex == 1)
//		func->acc = 1;
//	if(func->acc >= 1)
//		func->acc = func->acc - 1;       // ego kod







	string = ft_print_exponent_double(string, func, nbr);
	func->acc = acc;

	if(string == NULL)
	{
		string = ft_print_float(string, func, nbr);
		string =ft_del_zero(string, func);
	}
	return (string);
}
