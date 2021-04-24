/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:05 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/24 15:07:38 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

// TODAS BIEN

int				rrx(t_check *check, char *line)
{
	if (strcmp((const char *)line, "rra") == 0)
		return (rra(&check->a));
	else if (strcmp((const char *)line, "rrb") == 0)
		return (rrb(&check->b));
    else if (strcmp((const char *)line, "rrr") == 0)
        return (rrr(check));
	else
		return (1);
}

int				rra(t_stack **a)
{
    t_stack     *aux;

    if ((*a) && ((*a)->next != NULL))
    {
        aux = *a;
		*a = ft_lstlast(a);
		(*a)->next = aux;
		while (aux->next != *a)
			aux = aux->next;
		aux->next = NULL;
    }
    else
		return (print_error("Error en: rra\n"));
    return (0);
}

int				rrb(t_stack **b)
{
    t_stack     *aux;

    if ((*b) && ((*b)->next != NULL))
    {
        aux = *b;
		*b = ft_lstlast(b);
		(*b)->next = aux;
		while (aux->next != *b)
			aux = aux->next;
		//print_pointers(*a);
		aux->next = NULL;
    }
    else
		return (print_error("Error en: rrb\n"));
    return (0);
}

int				rrr(t_check *check)
{
	rra(&check->a);
	rrb(&check->b);
	write(1, "rrr\n", 4);
	return (0);
}
