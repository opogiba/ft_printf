/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:29:12 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/06 15:29:14 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include <wchar.h>


typedef enum 		s_len
{
	N,
	HH,
	H,
	L,
	LL,
	J,
	Z
}					t_len;


typedef struct	s_time
{
	int year_start;
	unsigned long sec;
	unsigned long min;
	unsigned long hour;
	unsigned long day;
	unsigned long month;
	int year;
}				t_time;

typedef struct		s_arg
{
	int				acc_ex;
	int				width_ex;
	int				f_hash;
	int				f_zero;
	int				f_minus;
	int				f_plus;
	int				f_space;
	int 			f_dollar;
	int 			f_dol_val;
	int 			f_apos;
	int 			width;
	int				acc;
	int  			base;
	int 			doub_len;
	char			chr;
	t_len			len;
}					t_arg;


typedef struct s_format
{
	int 	fd;
	int		format_written;
	int 	inx;
	const char *str;

}				t_format;

void	ft_check_percent(t_format *form, t_arg *func, va_list args, va_list tmp);

void				ft_clean(t_arg *func);
char				**ft_print_color(void);
char				**ft_choose_color(void);
char				**ft_fd_mas(void);
char				*ft_wchar_to_int(wint_t wint);
void				ft_print(char *str, t_format *form);
int					ft_choose_fd(char **fd_mas, t_format *form, va_list args);
int					ft_compare_color(char **color, char **print_color, t_format *form);
long long			ft_cust_id(t_arg *func, va_list args);
unsigned long long	ft_cust_uxo(t_arg *func, va_list args);
char				*ft_utoa_base(unsigned long long value, int b, t_arg *func);
char 				*ft_join_prefix(char *str, t_arg *func, int minus, int flag);
char				*ft_put_apostrophe(char *string, t_arg *func);
void				ft_convert_time(t_time *tm, unsigned long long time);
char				*ft_accuracy_string(t_arg *func, char *string);
char				*ft_accuracy_int(t_arg *func, char *str, unsigned long long nbr);
char 				*ft_width_int(t_arg *func, char *str, int minus, int i);
void				ft_join_symbol(t_arg *func, char a, t_format *form, char b);
char 				*ft_join_symbols(t_arg *func, char *str, int i, char c);
void				ft_change_list(va_list args,va_list tmp, t_arg *func);
void 				ft_parsing(t_format *form, t_arg *func, va_list args);
void				ft_parsing_accuracy(t_format *form, t_arg *func, va_list args);
void				ft_parsing_width(t_format *form, t_arg *func, va_list args);
void				ft_parsing_flags(t_format *form, t_arg *func, int i);
void				ft_parsing_length(t_format *fr, t_arg *func);
void				ft_parsing_brace(t_format *form, va_list args);
void 				ft_parsing_base(t_arg *func);
void 				ft_parsing_specifier(t_arg *func, unsigned long long nbr);
long double			ft_parsing_znak_double(long double nbr, t_arg *func);
void				ft_handle_specifier(t_format *form, t_arg *func, va_list args);
void				ft_pointer_to_int(t_format *form, va_list  args);
void				ft_print_time (t_format *form, t_arg *func, va_list args);
void				ft_print_int(t_format *form, t_arg *func, va_list args);
void 				ft_print_string(t_format *form, t_arg *func, va_list args);
void 				ft_print_char(t_format *form, t_arg *func, va_list args);
void				ft_print_memory(t_format *form, t_arg *func, va_list  args);
void				ft_print_double(t_format *form, t_arg *func, va_list args);
void				ft_print_non_printable(t_format *form, t_arg *func, va_list args);
char 				*ft_print_exponent_double(char *string, t_arg *func, long double nbr);
char 				*ft_print_float(char *string, t_arg *func, long double nbr);
char 				*ft_check_inf(long double nbr,t_arg *func);
long double			ft_ceil(long double nbr);
long double			ft_floor(long double nbr);
long double			ft_r_nbr(long double nbr);
char				*ft_round(long double nbr, t_arg *func, char *str);
int					ft_nbrlen(unsigned long long i, unsigned long long base);
char 				*ft_dot_to_float(char *string, t_arg *func);
char 				*ft_check_len(int len1, int len2, char *finish);


char 				*ft_check_g(int count, char *string, t_arg *func, long double nbr);
char 	*ft_del_zero(char *string, t_arg *func);
char 	*ft_do_exponent_string(long double nbr, t_arg *func, int count);
char 	*ft_print_float_or_exponent(char *string, t_arg *func, long double nbr);


char		*ft_round_d(long double nbr, t_arg *func, char *str);