/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:08 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/14 12:52:54 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

//  TODO BIEN, REVISAR RETURNS

int				px(t_check *check, char *line)
{
	if (strcmp((const char *)line, "pa") == 0)
		return (pa(&check->a, &check->b));
	else if (strcmp((const char *)line, "pb") == 0)
		return (pb(&check->a, &check->b));
	return (1);
}

int				pa(t_stack **a, t_stack **b)
{
	t_stack *aux, *aux2;

	if (*b)
	{
		aux2 = (*b)->next;
		aux = (*b);
		ft_lstadd_front(a, aux);
		*b = aux2;
		write(1, "pa\n", 3);
	}
	else
		return (print_error("Error: No existe el stack b\n"));
	print_list(*a);
	return (0);
}

int				pb(t_stack **a, t_stack **b)
{
	t_stack *aux, *aux2;

	if (*a)
	{
		aux2 = (*a)->next;
		aux = (*a);
		ft_lstadd_front(b, aux);
		*a = aux2;
		write(1, "pb\n", 3);
	}
	else
		return (print_error("Error: No existe el stack a\n"));
	print_list(*a);
	return (0);
}
