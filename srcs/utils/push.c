/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:08 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:12:38 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

//  TODO BIEN, REVISAR RETURNS

int				px(t_check *check, char *line)
{
	if (strcmp((const char *)line, "pa") == 0)
		return (pa(check));
	else if (strcmp((const char *)line, "pb") == 0)
		return (pb(check));
	return (1);
}

int				pa(t_check *check)
{
	t_stack *aux, *aux2;

	if (check->b)
	{
		aux2 = (check->b)->next;
		aux = (check->b);
		ft_lstadd_front(&(check->a), aux);
		check->b = aux2;
		write(1, "pa\n", 3);
	}
	else
		return (print_error("Error: No existe el stack b\n"));
	return (0);
}

int				pb(t_check *check)
{
	t_stack *aux, *aux2;

	if (check->a)
	{
		aux2 = (check->a)->next;
		aux = (check->a);
		ft_lstadd_front(&(check->b), aux);
		check->a = aux2;
		write(1, "pb\n", 3);
	}
	else
		return (print_error("Error: No existe el stack a\n"));
	return (0);
}
