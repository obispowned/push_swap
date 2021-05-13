/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:03 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/13 20:28:03 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int				rx(t_check *check, char *line)
{
	if (strcmp((const char *)line, "ra") == 0)
    {
        write(1, "ra\n", 3);
		return (ra(check));
    }
	else if (strcmp((const char *)line, "rb") == 0)
    {
        write(1, "rb\n", 3);
		return (rb(check));
    }
    else if (strcmp((const char *)line, "rr") == 0)
        return (rr(check));
    return (1);
}

int				ra(t_check *check)
{ /* BIEN */
    t_stack     *aux;

    if ((check->a) && ((check->a)->next != NULL))
    {
        aux = check->a;
        check->a = check->a->next;
        ft_lstadd_back(&(check->a), aux);
    }
    else
		return (print_error("Error en: ra\n"));
    return (0);
}

int				rb(t_check *check)
{ /* BIEN */
    t_stack     *aux;

    if ((check->b) && ((check->b)->next != NULL))
    {
        aux = check->b;
        check->b = (check->b)->next;
        ft_lstadd_back(&(check->b), aux);
    }
    else
		return (print_error("Error en: rb\n"));
    return (0);
}

int				rr(t_check *check)
{
    ra(check);
	rb(check);
	write(1, "rr\n", 3);
	return (0);
}
