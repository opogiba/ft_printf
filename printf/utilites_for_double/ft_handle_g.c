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
	if((exponenta < -4 ) || (exponenta >= func->acc && func->acc_ex == 1))
	{
		string = ft_do_exponent_string(nbr, func, exponenta);
		return (string);
	}
	else
		return (NULL);
}