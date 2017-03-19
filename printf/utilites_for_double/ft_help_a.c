#include "../../ft_printf.h"

char	*ft_do_first_hex_string(char *final, t_arg *func, double long nbr)
{
	final = ft_strdup("");
	func->f_hash = 1;
	if (func->chr == 'A')
		func->chr = 'X';
	else
		func->chr = 'x';
	if (nbr == 0.0)
		final = ft_join_char(final, 0, '0');
	else if (nbr > 0.0 || nbr < 0.0)
		final = ft_join_char(final, 0, '1');
	return (final);
}

char	*ft_do_last_hex_string(char *final, t_arg *func, int exponent)
{
	char	*tmp;

	final = ft_strdup("");
	if (func->chr == 'X')
		final = ft_join_char(final, 0, 'P');
	else
		final = ft_join_char(final, 0, 'p');
	if (exponent < 0)
		final = ft_join_char(final, 0, '-');
	else
		final = ft_join_char(final, 0, '+');
	if (exponent < 0)
		exponent *= -1;
	tmp = final;
	final = ft_strjoin(final, ft_itoa_base(exponent, 10));
	free(tmp);
	return (final);
}

char 	*ft_do_fraction_string(char *final, t_arg *func, long double nbr)
{
	int i;
	int base;
	int j;

	j = 0;
	i = func->acc;
	final = (char*)malloc(sizeof(char) * i + 1);
	base = (int)nbr;
	nbr = nbr - (long double)base;
	while (func->acc )
	{
		nbr = nbr * 16;
		base = (int)nbr;
		nbr = nbr -(long double)base;
		if(base >= 10)
			final[j] = base - 10 + func->chr - 23;
		else
			final[j] = base +'0';
		j++;
		func->acc--;
	}
	final[j] = '\0';
	return (final);
}

char 	*ft_del_z(char *second_part, char *fin, t_arg *func)
{
	int i;
	int j;

	j = (int)ft_strlen(second_part) - 1;
	i = j;
	if(func ->acc_ex != -1)
		i--;
	while (j  >=  0 && func->acc_ex == -1)
	{
		if (second_part[j] != '0')
		{
			i--;
			break;
		}
		if (second_part[j] == '0')
		{
			second_part[j] = '\0';
			i--;
		}
		j--;
	}
	if (j != i)
		fin = ft_join_char(fin, 0, '.');
	return (fin);
}