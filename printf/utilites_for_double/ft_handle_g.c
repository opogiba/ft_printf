#include "../../ft_printf.h"

char 	*ft_del_zero(char *string, t_arg *func)
{
	int len;
	char a;

	a = '.';
	len = (int)ft_strlen(string);
	if(ft_strchr(string, a) && func->f_hash == 0)
	{
		len = len - 1;
		while (string[len] == '0')
		{
			string[len--] = '\0';
		}
		if(string[len] == '.')
			string[len] = '\0';
	}
	return (string);
}

char 	*ft_check_g(int exponenta, char *string, t_arg *func, long double nbr)
{
	int len;
	int acc;


	acc = func->acc;

	len = (long int)ft_strlen(ft_itoa((long int)nbr));
	func->acc = func->acc - len;
	func->acc = func->acc >= 0 ? func->acc : 0;

	if(((exponenta < -4 ) || (exponenta >= func->acc && func->acc_ex == 1)) && len > acc )
	{
		string = ft_do_exponent_string(nbr, func, exponenta);
		return (string);
	}
	else
		return (NULL);
}