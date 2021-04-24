/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:07:54 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/24 16:23:25 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int		str_array_length(char **arr)
{
	int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (i < str_array_length(arr))
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int		no_repeated_numbers(char **arr)
{
	int	i, j;

	i = 0;
	while (i < str_array_length(arr))
	{
		j = i;
		while (++j < str_array_length(arr))
		{
			if (!ft_strcmp(arr[i], arr[j]))
				return (0);
		}
		i++;
	}
	return (1);
}
