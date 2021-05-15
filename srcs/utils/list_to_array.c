/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:59:51 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/15 17:43:58 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

long	*order_array(long	*a, int nelementos)
{
	int		i;
	int		j;
	long	temp;

	temp = 0;
	i = 1;
	while (i < nelementos)
	{
		j = 0;
		while (j < nelementos - i)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (a);
}

long	*fill_me_array(t_check *check)
{
	t_stack	*stack;
	long	*a;
	int		i;

	stack = check->a;
	i = 0;
	a = (long *)malloc(sizeof(long) * (ft_lstlen(check->a)));
	while (i < ft_lstlen(check->a) && stack != NULL)
	{
		a[i] = stack->content;
		stack = stack->next;
		i++;
	}
	a = order_array(a, ft_lstlen(check->a));
	return (a);
}
