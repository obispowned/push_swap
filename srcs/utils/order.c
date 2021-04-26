/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:07:47 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/26 19:56:54 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void		order_4(t_check *check)
{
	long	*a;
	t_stack	*stack;

	stack = check->a;
	a = fill_me_array(check);
	while (stack && stack->content != a[0])
	{
		ra(check);
		stack = stack->next;
	}
	pb(check);
	order_3(check);
	pa(check);
}

void		order_5(t_check *check)
{
	long	*a;
	t_stack	*stack;
	int		flag;

	flag = 0;
	stack = check->a;
	a = fill_me_array(check);
	printf("%ld-%ld-%ld-%ld-%ld\n", a[0],a[1],a[2],a[3],a[4]);
	while (flag != 2)
	{
		if (stack->content == a[0] || stack->content == a[1])
		{
			pb(check);
			flag++;
		}
		rra(check);
		stack = check->a;
	}
	if (check->a->content < (check->a->next)->content)
		sb(check);
	pa(check);
	pa(check);
}

/*
static void		solve_5(t_frame *frame)
{
	t_stack *stack_a_end;
	t_stack	*tmp;
	int		flag;

	flag = 0;
	stack_a_end = frame->a->prev;
	median(frame, 'a');
	while (flag != 1)
	{
		frame->a == stack_a_end ? flag = 1 : 0;
		if (frame->a->num < MEDIAN)
			do_pb(frame);
		else
			do_ra(frame);
	}
	solve_3(frame);
	tmp = frame->b->next;
	frame->b->num < tmp->num ? do_sb(frame) : 0;
	do_pa(frame);
	do_pa(frame);
}*/


void	order_3(t_check *check)
{
	if (check->a->content > (check->a->next)->content && check->a->content < ((check->a->next)->next)->content) //case 2 1 3
		sa(check);
	else if (check->a->content > (check->a->next)->content && (check->a->next)->content > ((check->a->next)->next)->content) //case 3 2 1
	{
		sa(check);
		rra(check);
	}
	else if (check->a->content > (check->a->next)->content && (check->a->next)->content < ((check->a->next)->next)->content) //case 3 1 2
		ra(check);
	else if (check->a->content < (check->a->next)->content && (check->a->next)->content > ((check->a->next)->next)->content
	&& check->a->content < ((check->a->next)->next)->content) //case 1 3 2
	{
		sa(check);
		ra(check);
	}
	else if (check->a->content < (check->a->next)->content && check->a->content > ((check->a->next)->next)->content) //case 2 3 1
	{
		rra(check);
	}
	else
		printf("El algoritmo order_3 esta dando problemas\n");
}

void	order_2(t_check *check)
{
	if (check->a->content > (check->a->next)->content)
		sa(check);
}

void	ia_order(t_check	*check)
{
	printf("Estado de stackA al comenzar el programa:\n");
	print_list(check->a, 'A');
	printf("\n");
	if (ft_lstlen(check->a) == 2)
		order_2(check);
	if (ft_lstlen(check->a) == 3)
		order_3(check);
	if (ft_lstlen(check->a) == 4)
		order_4(check);
	if (ft_lstlen(check->a) == 5)
		order_5(check);
}
