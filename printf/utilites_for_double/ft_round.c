#include "../../ft_printf.h"

long double	ft_ceil(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr <= i)
		return (i);
	return (i + 1);
}

long double	ft_floor(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr >= i)
		return (i);
	return (i - 1);
}

long double	ft_r_nbr(long double nbr)
{
	if (nbr - ft_floor(nbr) == 0.5 && (long long)ft_floor(nbr) % 2 == 0)
		return (ft_floor(nbr));
	else if (ft_ceil(nbr) - nbr == 0.5)
		return (ft_ceil(nbr));
	if(nbr - ft_floor(nbr) >= 0.5)
		return (ft_ceil(nbr));
	else
		return (ft_floor(nbr));
}

//char		*ft_round(long double nbr, t_arg *func, char *str)
//{
//	int			i;
//	int			acc;
//	int 		j;
//
//	j = 0;
//	acc = func->acc;
//	while (acc > 0)
//	{
//		nbr *= 10;
//		if (acc == 1)
//			nbr = ft_r_nbr(nbr);
//		i = (int) nbr;
//		str[j] = (char)(i + '0');
//		nbr = nbr - i;
//		acc--;
//		j++;
////		*str = i + '0';
////		nbr = nbr - i;
////		acc--;
////		str++;
//	}
//	return (str);
//}

//char		*ft_round_d(long double nbr, t_arg *func, char *str)
//{
//	int			acc;
//	long long	nbr_l;
//	int 		i;
//
//	i = 0;
//
//	acc = func->acc;
//	while (acc > 0)
//	{
//		nbr *= 10;
//		acc--;
//	}
//	nbr_l = ft_r_nbr(nbr);
//	acc = func->acc - ft_nbrlen(nbr_l, 10);
//	while (acc > 0)
//	{
//		str[i] = '0';
//		i++;
//		acc--;
//
////		*str = '0';
////		str++;
////		acc--;
//	}
//	if(i != 0)
//	{
//		str = ft_strjoin(str,ft_itoa_base(nbr_l, 10));
//		return (str);
//	}
//	str = ft_itoa_base(nbr_l, 10);
////	nbr_to_str(nbr_l, 10, &str);
//	return (str);
//}
char		*ft_round(long double nbr, t_arg *func, char *str)
{
	int			i;
	int			p;

	p = func->acc;
	while (p > 0)
	{
		nbr *= 10;
		if (p == 1)
			nbr = ft_r_nbr(nbr);
		i = (int)nbr;
		*str = i + '0';
		nbr = nbr - i;
		p--;
		str++;
	}
	return (str);
}
void		ft_round_d(long double nbr, t_arg *func, char *str)
{
	int			p;
	long long	nbr_l;

	p = func->acc;
	while (p > 0)
	{
		nbr *= 10;
		p--;
	}
	nbr_l = ft_r_nbr(nbr);
	p = func->acc - ft_nbrlen(nbr_l, 10);
	while (p > 0)
	{
		*str = '0';
		str++;
		p--;
	}
	nbr_to_str(nbr_l, 10, &str);
}
//char		*ft_round_d(long double nbr, t_arg *func, char *str)
//{
//	int			p;
//	long long	nbr_l;
//	int i;
//
//	i = 0;
//
//	p = func->acc;
//	while (p > 0)
//	{
//		nbr *= 10;
//		p--;
//	}
//	nbr_l = ft_r_nbr(nbr);
//	p = func->acc - ft_nbrlen(nbr_l, 10);
//	while (p > 0)
//	{
//		str[i] = '0';
//		i++;
//		p--;
//	}
//	str[i] = '\0';
//	char *string;
//	string = ft_itoa_base(nbr_l, 10);
//	str = ft_strjoin(str, string);
//	return (str);
//}