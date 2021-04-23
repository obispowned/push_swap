#include <push_swap.h>

int	no_repeated_numbers(char **arr)
{
	int	i, j;

	i = 0;
	while (i < str_array_length(arr))
	{
		j = i;
		while (++j < str_array_lenght(arr))
		{
			if (!ft_strcmp(arr[i], arr[j]))
				return (0);
		}
		i++;
	}
	return (1);
}
