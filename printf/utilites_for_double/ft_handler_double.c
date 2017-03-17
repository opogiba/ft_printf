#include "../../ft_printf.h"

char 	*ft_check_len(int len1, int len2, char *finish)
{
	int i;

	i = 0;
	len1--;
	while(ft_isdigit(finish[i]))
		i++;
	while(i < len2)
	{
		finish[i] = '0';
		i++;
	}
	return (finish);
}

int		ft_nbrlen(unsigned long long i, unsigned long long base)
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

char 	*ft_dot_to_float(char *string, t_arg *func)
{
	char *tmp;

	if(func->acc != 0)
	{
		tmp = string;
		string = ft_strjoin(string, ".");
		free(tmp);
	}
	else if(func->f_hash == 1 )
	{
		tmp = string;
		string = ft_strjoin(string, ".");
		free(tmp);

	}
	return (string);
}

