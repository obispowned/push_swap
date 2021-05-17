/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:07:47 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/17 17:13:23 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	order_4(t_check *check, long *arr)
{
	t_stack	*stack;

	stack = check->a;
	if (!(is_this_order(check->a)))
	{
		while ((stack) && (stack->content != arr[0]))
		{
			rx(check, "ra", 'p');
			stack = check->a;
		}
		px(check, "pb", 'p');
		order_3(check);
		px(check, "pa", 'p');
	}
}

void	order_5(t_check *check, long *a)
{
	t_stack	*stack;
	int		flag;

	flag = 0;
	stack = check->a;
	if (!(is_this_order(check->a)))
	{
		while (flag != 2)
		{
			if (stack->content == a[0] || stack->content == a[1])
			{
				px(check, "pb", 'p');
				flag++;
			}
			rrx(check, "rra", 'p');
			stack = check->a;
		}
		order_3(check);
		if (check->b->content < (check->b->next)->content)
			sx(check, "sb", 'p');
		px(check, "pa", 'p');
		px(check, "pa", 'p');
	}
}

int	order_3(t_check *check)
{
	if (!(is_this_order(check->a)))
	{
		if (check->a->content > (check->a->next)->content
			&& check->a->content < ((check->a->next)->next)->content)
			return (order_3_c213(check));
		else if (check->a->content > (check->a->next)->content
			&& (check->a->next)->content > ((check->a->next)->next)->content)
			return (order_3_c321(check));
		else if (check->a->content > (check->a->next)->content
			&& (check->a->next)->content < ((check->a->next)->next)->content)
			return (order_3_c312(check));
		else if (check->a->content < (check->a->next)->content
			&& (check->a->next)->content > ((check->a->next)->next)->content
			&& check->a->content < ((check->a->next)->next)->content)
			return (order_3_c132(check));
		else if (check->a->content < (check->a->next)->content
			&& check->a->content > ((check->a->next)->next)->content)
			return (order_3_c231(check));
		return (0);
	}
	return (0);
}

void	order_2(t_check *check)
{
	if (check->a->content > (check->a->next)->content)
		sx(check, "sa", 'p');
}

void	ia_order(t_check	*check)
{
	long	*a;

	a = fill_me_array(check);
	tell_me_the_positions(&(check->a), a);
	if (ft_lstlen(check->a) == 2)
		order_2(check);
	if (ft_lstlen(check->a) == 3)
		order_3(check);
	if (ft_lstlen(check->a) == 4)
		order_4(check, a);
	if (ft_lstlen(check->a) == 5)
		order_5(check, a);
	if ((ft_lstlen(check->a) > 5) && (ft_lstlen(check->a) < 101))
		order_100(check, a);
	else if ((ft_lstlen(check->a) > 100) && (ft_lstlen(check->a) < 501))
		order_500(check, a);
	free (a);
}
