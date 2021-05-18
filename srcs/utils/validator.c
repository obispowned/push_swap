/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:07:54 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 17:30:14 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	str_array_length(char **arr)
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

int	no_repeated_numbers(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < str_array_length(arr))
	{
		j = i;
		while (++j < str_array_length(arr))
		{
			if (!ft_strcmp(arr[i], arr[j])
				|| ft_atol(arr[i]) == ft_atol(arr[j]))
				return (0);
		}
		i++;
	}
	return (1);
}

char	*check_OK_KO(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	if (tmp)
	{
		i = tmp->content;
		tmp = tmp->next;
		while (tmp->next != NULL)
		{
			if (i > tmp->content)
				return ("KO\n");
			i = tmp->content;
			tmp = tmp->next;
		}
		if (i > tmp->content)
			return ("KO\n");
	}
	else
		return ("KO\n");
	return ("OK\n");
}

int	is_this_order(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux)
	{
		if (aux->next)
		{
			if (aux->content > aux->next->content)
				return (0);
		}
		aux = aux->next;
	}
	return (1);
}
