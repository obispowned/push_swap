/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:03 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/14 17:16:12 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int				rx(t_check *check, char *line)
{
	if (strcmp((const char *)line, "ra") == 0)
		return (ra(&check->a));
	else if (strcmp((const char *)line, "rb") == 0)
		return (rb(&check->b));
    else if (strcmp((const char *)line, "rr") == 0)
        return (rr(check));
    return (1);
}

int				ra(t_stack **a)
{ /* BIEN */
    t_stack     *aux;

    if ((*a) && ((*a)->next != NULL))
    {
        aux = *a;
        *a = (*a)->next;
        ft_lstadd_back(a, aux);
    }
    else
		return (print_error("Error en: ra\n"));
    return (0);
}

int				rb(t_stack **b)
{ /* BIEN */
    t_stack     *aux;

    if ((*b) && ((*b)->next != NULL))
    {
        aux = *b;
        *b = (*b)->next;
        ft_lstadd_back(b, aux);
    }
    else
		return (print_error("Error en: rb\n"));
    return (0);
}

int				rr(t_check *check)
{
    ra(&check->a);
	rb(&check->b);
	write(1, "rr\n", 3);
	return (0);
}
