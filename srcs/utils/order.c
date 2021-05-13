/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:07:47 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/13 21:23:21 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void		order_4(t_check *check)
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

void		order_5(t_check *check)
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

int		order_3(t_check *check)
{
	int	cantidad_ops;

	cantidad_ops = 0;
	if (check->a->content > (check->a->next)->content && check->a->content < ((check->a->next)->next)->content) //case 2 1 3
	{
		cantidad_ops = 1;
		sx(check, "sa");
	}
	else if (check->a->content > (check->a->next)->content && (check->a->next)->content > ((check->a->next)->next)->content) //case 3 2 1
	{
		sx(check, "sa");
		rrx(check, "rra");
		cantidad_ops = 2;
	}
	else if (check->a->content > (check->a->next)->content && (check->a->next)->content < ((check->a->next)->next)->content) //case 3 1 2
	{
		rx(check, "ra");
		cantidad_ops = 1;
	}
	else if (check->a->content < (check->a->next)->content && (check->a->next)->content > ((check->a->next)->next)->content
	&& check->a->content < ((check->a->next)->next)->content) //case 1 3 2
	{
		sx(check, "sa");
		rx(check, "ra");
		cantidad_ops = 2;
	}
	else if (check->a->content < (check->a->next)->content && check->a->content > ((check->a->next)->next)->content) //case 2 3 1
	{
		rrx(check, "rra");
		cantidad_ops = 1;
	}
	else
		printf("El algoritmo order_3 esta dando problemas\n");
	return (cantidad_ops);
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
