/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:07:47 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:08:25 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

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
}
