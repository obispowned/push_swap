/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:47:25 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/27 20:03:33 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void		rotate_and_push_to_a(t_check *check)
{
	if (check->small_rotate >= 0)
		while (check->small_rotate--)
			rb(check);
	else if (check->small_rrotate >= 0)
		while (check->small_rrotate--)
			rrb(check);
	else if (check->big_rotate >= 0)
		while (check->big_rotate--)
			rb(check);
	else if (check->big_rrotate >= 0)
		while (check->big_rrotate--)
			rrb(check);
	pa(check);
	check->small_flag ? ra(check) : 0;
	(check->big_flag || !check->b) ? check->after_rotate++ : 0;
}

void		push_big_small(t_check *check, t_stack *stack, t_stack *stack_end)
{
	while (1)
	{
		while (stack->content != check->smallest && stack->content != check->biggest)
			stack = stack->next;
		if (stack->content == check->smallest || stack->content == check->biggest)
		{
			rotate_and_push_to_a(check);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = check->b;
	}
}
