#include "../../ft_printf.h"

char	*ft_check_g(int exponenta, char *string, t_arg *func, long double nbr)
{
	int len;
	int acc;

	acc = func->acc;
	len = (int)ft_strlen(ft_itoa_base((long int)nbr, 10));
	func->acc = func->acc - len;
	func->acc = func->acc >= 0 ? func->acc : 0;
	if ((exponenta < -4) || (exponenta >= func->acc && func->acc_ex == 1))
	{
		string = ft_do_exponent_string(nbr, func, exponenta);
		return (string);
	}
	else
	{
		func->acc = acc;
		return (NULL);
	}
}
