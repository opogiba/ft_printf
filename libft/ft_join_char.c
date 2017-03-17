#include "../libft.h"

char	*ft_join_char(char *str, int flag, char c)
{
	char	*zero;
	char	*tmp;

	zero = ft_strdup(" ");
	zero[0] = c;
	tmp = str;
	if(flag == 0)
	{
		str = ft_strjoin(str, zero);
	}
	else
		str = ft_strjoin(zero, str);
	free(tmp);
	free(zero);
	return (str);
}