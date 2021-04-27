/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_big_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:02:45 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/27 19:03:34 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	find_biggest(t_check *check, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	stack = (stack_name == 'a') ? check->a : check->b;
	tmp = stack;
	check->biggest = tmp->content;
	end = (stack_name == 'a') ? ft_lstlast(&(check->a)) : ft_lstlast(&(check->b));
	while (1)
	{
		if (tmp->content > check->biggest)
			check->biggest = tmp->content;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest_smallest(t_check *check, char stack_name)
{
	t_stack		*stack;

	stack = (stack_name == 'a') ? check->a : check->b;
	find_biggest(check, stack_name);
	find_smallest(check, stack_name);
}

void	find_smallest(t_check *check, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	stack = (stack_name == 'a') ? check->a : check->b;
	tmp = stack;
	end = (stack_name == 'a') ? ft_lstlast(&(check->a)) : ft_lstlast(&(check->b));
	check->smallest = check->biggest;
	while (1)
	{
		if (tmp->content <= check->smallest)
			check->smallest = tmp->content;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}
