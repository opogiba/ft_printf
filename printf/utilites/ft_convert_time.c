/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:36:24 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/16 18:38:51 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int			ft_check_year(int year)
{
	return ((!((year) % 4) && (((year) % 100) || !((year) % 400))));
}

int			ft_year_size(int year)
{
	if (ft_check_year(year))
		return (366);
	return (365);
}

static int	**ft_mas_month(void)
{
	int	**month_day;
	int i;

	month_day = (int **)malloc(sizeof(int *) * 2);
	month_day[0] = (int *)malloc(sizeof(int) * 12);
	month_day[0][0] = 31;
	month_day[0][1] = 28;
	month_day[0][2] = 31;
	month_day[0][3] = 30;
	month_day[0][4] = 31;
	month_day[0][5] = 30;
	month_day[0][6] = 31;
	month_day[0][7] = 31;
	month_day[0][8] = 30;
	month_day[0][9] = 31;
	month_day[0][10] = 30;
	month_day[0][11] = 31;
	month_day[1] = (int *)malloc(sizeof(int) * 12);
	i = -1;
	while (++i < 12)
		month_day[1][i] = month_day[0][i];
	month_day[1][1] = 29;
	return (month_day);
}

void		ft_convert_time(t_time *tm, unsigned long long time)
{
	unsigned long	dayclock;
	unsigned long	dayno;
	int				**month_day;

	tm->year_start = 1970;
	month_day = ft_mas_month();
	dayclock = time % (24 * 60 * 60);
	dayno = time / (24 * 60 * 60);
	tm->sec = dayclock % 60;
	tm->min = (dayclock % 3600) / 60;
	tm->hour = dayclock / 3600;
	while ((int)dayno >= ft_year_size(tm->year_start))
	{
		dayno -= ft_year_size(tm->year_start);
		tm->year_start++;
	}
	tm->year = tm->year_start;
	tm->month = 0;
	while ((int)dayno >= month_day[ft_check_year(tm->year_start)][tm->month])
	{
		dayno -= month_day[ft_check_year(tm->year_start)][tm->month];
		tm->month++;
	}
	tm->month = tm->month + 1;
	tm->day = dayno + 1;
}
