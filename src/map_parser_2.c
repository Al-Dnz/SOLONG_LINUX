#include "solong.h"

int	count_symbol(char **map, char symbol)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == symbol)
				res++;
			i++;
		}
		j++;
	}
	return (res);
}
