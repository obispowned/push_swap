/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:28:04 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/27 19:42:41 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void		moves_to_start(t_check *check, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? check->a : check->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? check->a : check->b;
		element = (flag == 1) ? check->smallest : check->biggest;
		while (tmp->content != element)
		{
			flag == 1 ? check->small_rotate++ : check->big_rotate++;
			tmp = tmp->next;
		}
	}
}

/*
** Calculates moves to bottom of stack
*/

void		moves_to_end(t_check *check, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? check->a : check->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? ft_lstlast(&(check->a)) : ft_lstlast(&(check->b));
		element = (flag == 1) ? check->smallest : check->biggest;
		while (tmp->content != element)
		{
			flag == 1 ? check->small_rrotate++ : check->big_rrotate++;
			tmp = tmp->next; /***/
		}
		flag == 1 ? check->small_rrotate++ : check->big_rrotate++;
	}
}

void		moves_smallest(t_check *check, char stack_name)
{
	t_stack	*stack;
	int		flag;

	stack = (stack_name == 'a') ? check->a : check->b;
	flag = 1;
	if (stack)
	{
		moves_to_start(check, stack_name, flag);
		moves_to_end(check, stack_name, flag);
		if (check->small_rotate <= check->small_rrotate)
			check->small_rrotate = -1;
		else
			check->small_rotate = -1;
	}
}

void		moves_biggest(t_check *check, char stack_name)
{
	t_stack	*stack;
	int		flag;

	stack = (stack_name == 'a') ? check->a : check->b;
	flag = 2;
	if (stack)
	{
		moves_to_start(check, stack_name, flag);
		moves_to_end(check, stack_name, flag);
		if (check->big_rotate <= check->big_rrotate)
			check->big_rrotate = -1;
		else
			check->big_rotate = -1;
	}
}

void		find_moves(t_check *check, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? check->a : check->b;
	moves_smallest(check, 'b');
	moves_biggest(check, 'b');
	if (check->big_rotate != -1 && (check->big_rotate >= check->small_rotate &&
		check->big_rotate >= check->small_rrotate))
		check->big_rotate = -1;
	else if (check->big_rrotate != -1 && (check->big_rrotate >= check->small_rotate &&
		check->big_rrotate >= check->small_rrotate))
		check->big_rrotate = -1;
	else if (check->small_rotate != -1 && (check->small_rotate >= check->big_rotate &&
		check->small_rotate >= check->big_rrotate))
		check->small_rotate = -1;
	else if (check->small_rrotate != -1 && (check->small_rrotate >= check->big_rotate &&
		check->small_rrotate >= check->big_rrotate))
		check->small_rrotate = -1;
	if (check->small_rotate != -1 || check->small_rrotate != -1)
		check->small_flag = 1;
	else if (check->big_rotate != -1 || check->big_rrotate != -1)
		check->big_flag = 1;
}
