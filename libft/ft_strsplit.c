/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 23:27:05 by opogiba           #+#    #+#             */
/*   Updated: 2016/12/05 18:46:22 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		word_count(char *str, char c)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (str[count])
	{
		j = 0;
		while (str[count] == c && str[count])
			count++;
		while (str[count] != c && str[count])
		{
			j++;
			count++;
		}
		if (j != 0)
			i++;
	}
	return (i);
}

static char		**newstroke(char c, char *str)
{
	char **res;

	res = (char**)malloc(sizeof(char*) * (word_count(str, c) + 1));
	if (!res)
		return (NULL);
	return (res);
}

static int		count(char *str, char c)
{
	int count;
	int i;
	int j;

	i = 0;
	count = 0;
	j = 0;
	while (str[count] != c && str[count] != '\0')
	{
		count++;
		j++;
	}
	return (j);
}

static char		**newmas(char *str, char **array, char c)
{
	int j;
	int a;
	int b;

	a = 0;
	b = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] != c && str[j] != '\0')
		{
			array[a] = (char*)malloc(sizeof(char) * (count(&str[j], c) + 1));
			if (!array[a])
				return (NULL);
			b = 0;
			while (str[j] != c && str[j] != '\0')
				array[a][b++] = str[j++];
			array[a++][b] = '\0';
		}
		if (str[j] == c && str[j] != '\0')
			j++;
	}
	array[a] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;

	array = NULL;
	if (s)
	{
		array = newstroke(c, (char*)s);
		if (!array)
			return (NULL);
		array = newmas((char*)s, array, c);
		if (!array)
			return (NULL);
	}
	return (array);
}
