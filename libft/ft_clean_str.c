#include "../libft.h"

char 	*ft_clean_str(char *nbr)
{
	free(nbr);
	nbr = ft_strdup("");
	return (nbr);
}
