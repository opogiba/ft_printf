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

char 	*ft_check_g(int count, char *string, t_arg *func, long double nbr)
{
	if((count < -4  || (count >= func->acc)) && func->base == 10 && func->acc != 0)
	{
		string = ft_do_exponent_string(nbr, func, count);
		return (string);
	}
	else if((count >= -4  || (count < func->acc)) && func->base != 11)
		return (NULL);
	string = ft_do_exponent_string(nbr, func, count);
	return (string);

}