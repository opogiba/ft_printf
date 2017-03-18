#include "../../ft_printf.h"

char	*ft_dot_to_float(char *string, t_arg *func)
{
	char *tmp;

	if (func->acc != 0)
	{
		tmp = string;
		string = ft_strjoin(string, ".");
		free(tmp);
	}
	else if (func->f_hash == 1)
	{
		tmp = string;
		string = ft_strjoin(string, ".");
		free(tmp);
	}
	return (string);
}