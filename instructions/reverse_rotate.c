/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:05 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/14 17:44:19 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int				rrx(t_check *check, char *line)
{
	if (strcmp((const char *)line, "rra") == 0)
		return (rra(&check->a));
	else if (strcmp((const char *)line, "rrb") == 0)
		return (rrb(check));
    else if (strcmp((const char *)line, "rrr") == 0)
        return (rrr(check));
	else
		return (1);
}

t_stack			*lst_prev_to_this(t_stack *stack)
{
	t_stack		*aux;

	aux = stack;
	if (stack)
	{
		while (aux->next != stack)
			aux = aux->next;
	}
	return (aux);
}

int				rra(t_stack **a)
{
    t_stack     *aux;

    if ((*a) && ((*a)->next != NULL))
    {
        aux = *a;
		*a = ft_lstlast(*a);
		(*a)->next = aux;
		aux = lst_prev_to_this(*a);
    }
    else
		return (print_error("Error en: ra\n"));
    return (0);
}

int				rrb(t_check *check)
{
	return (0);
}

int				rrr(t_check *check)
{

	return (0);
}
