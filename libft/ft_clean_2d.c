#include "../libft.h"

void	ft_clean_2dchar(char **nbr)
{
	int i;

	i = 0;
	while(nbr[i])
	{
		free(nbr[i]);
		i++;
	}
	free(nbr);
	nbr = NULL;
}


