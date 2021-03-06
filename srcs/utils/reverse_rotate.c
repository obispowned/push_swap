/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:05 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 17:13:40 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	rrx(t_check *check, char *line, char ps)
{
	if (strcmp((const char *)line, "rra") == 0)
	{
		if (ps == 'p')
			write(1, "rra\n", 4);
		return (rra(check));
	}
	else if (strcmp((const char *)line, "rrb") == 0)
	{
		if (ps == 'p')
			write(1, "rrb\n", 4);
		return (rrb(check));
	}
	else if (strcmp((const char *)line, "rrr") == 0)
	{
		if (ps == 'p')
			write(1, "rrr\n", 4);
		return (rrr(check));
	}
	else
		return (1);
}

int	rra(t_check *check)
{
	t_stack	*aux;

	if ((check->a) && ((check->a)->next != NULL))
	{
		aux = check->a;
		check->a = ft_lstlast(&(check->a));
		(check->a)->next = aux;
		while (aux->next != check->a)
			aux = aux->next;
		aux->next = NULL;
	}
	return (0);
}

int	rrb(t_check *check)
{
	t_stack	*aux;

	if ((check->b) && ((check->b)->next != NULL))
	{
		aux = check->b;
		check->b = ft_lstlast(&(check->b));
		(check->b)->next = aux;
		while (aux->next != check->b)
			aux = aux->next;
		aux->next = NULL;
	}
	return (0);
}

int	rrr(t_check *check)
{
	rra(check);
	rrb(check);
	return (0);
}
