/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:07:47 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/15 18:15:02 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	order_4(t_check *check)
{
	long	*arr;
	t_stack	*stack;

	stack = check->a;
	arr = fill_me_array(check);
	while ((stack) && (stack->content != arr[0]))
	{
		rx(check, "ra");
		stack = check->a;
	}
	pb(check);
	order_3(check);
	pa(check);
}

void	order_5(t_check *check)
{
	long	*a;
	t_stack	*stack;
	int		flag;

	flag = 0;
	stack = check->a;
	a = fill_me_array(check);
	while (flag != 2)
	{
		if (stack->content == a[0] || stack->content == a[1])
		{
			pb(check);
			flag++;
		}
		rrx(check, "rra");
		stack = check->a;
	}
	order_3(check);
	if (check->b->content < (check->b->next)->content)
		sx(check, "sb");
	pa(check);
	pa(check);
}

int	order_3(t_check *check)
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
	else
		print_exit("El algoritmo order_3 esta dando problemas\n");
	return (0);
}

void	order_2(t_check *check)
{
	if (check->a->content > (check->a->next)->content)
		sx(check, "sa");
}

void	ia_order(t_check	*check)
{
	long	*a;

	a = fill_me_array(check);
	tell_me_the_positions(&(check->a), a);
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
	if ((ft_lstlen(check->a) > 5) && (ft_lstlen(check->a) < 101))
		order_100(check, a);
	else if ((ft_lstlen(check->a) > 100) && (ft_lstlen(check->a) < 501))
		order_500(check, a);
}
