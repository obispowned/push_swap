/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:09:35 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/27 19:45:15 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void		sort_array(long *array, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

void		find_mid(t_check *check, t_stack *stack, char stack_name)
{
	long	*array;
	int		i;
	int		quarter_len;

	i = 0;
	if (stack_name == 'a')
		check->stack_len = ft_lstlen(check->a);
	if (stack_name == 'b')
		check->stack_len = ft_lstlen(check->b);
	quarter_len = check->stack_len / 4;
	if (!(array = (long*)malloc(sizeof(long) * (check->stack_len + 1))))
		print_exit("Error\n");
	while (i < check->stack_len)
	{
		array[i++] = stack->content;
		stack = stack->next;
	}
	sort_array(array, check->stack_len);
	check->quarter = array[quarter_len];
	check->median = array[quarter_len * 2];
	check->three_quarters = array[quarter_len * 3];
	free(array);
}

void		mid(t_check *check, char stack_name)
{ /*ok*/
	t_stack	*stack;

	stack = (stack_name == 'a') ? check->a : check->b;
	find_mid(check, stack, stack_name);
}

void		reset_moves(t_check *check)
{
	check->biggest = 0;
	check->big_rotate = 0;
	check->big_rrotate = 0;
	check->big_flag = 0;
	check->smallest = 0;
	check->small_rotate = 0;
	check->small_rrotate = 0;
	check->small_flag = 0;
}

void	push_mid(t_check *check, int split)
{ /**ok*/
	t_stack	*stack;
	t_stack	*stack_a_end;
	int		flag;

	stack = check->a;
	stack_a_end = ft_lstlast(&(check->a));;
	flag = 0;
	find_smallest(check, 'a');
	while (1)
	{
		if (stack == stack_a_end)
			flag = 1;
		if (split == 1 && stack->content <= check->median)
			pb(check);
		else if (split == 2 && stack->content > check->median)
			pb(check);
		else if (stack->content == check->smallest)
			break ;
		else
			ra(check);
		if (flag == 1)
			break;
		stack = check->a;
	}
	reset_moves(check);
}

void		order_100(t_check *check)
{
	int	split;

	split = 1;
	mid(check, 'a');
	while (check->a)
	{
		push_mid(check, split);
		while (check->b)
		{
			find_biggest_smallest(check, 'b');
			find_moves(check, 'b');
			if (check->b && (check->small_rotate >= 0 || check->small_rrotate >= 0
				|| check->big_rotate >= 0 || check->big_rrotate >= 0))
				push_big_small(check, check->b, ft_lstlast(&(check->b)));
		}
		while (--(check->after_rotate))
			ra(check);
		split++;
		if (split == 3)
			break ;
	}
}
