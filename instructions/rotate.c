/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:03 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/14 12:35:18 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int				rx(t_check *check, char *line)
{
	if (strcmp((const char *)line, "ra") == 0)
		return (ra(check));
	else if (strcmp((const char *)line, "rb") == 0)
		return (rb(check));
    else if (strcmp((const char *)line, "rr") == 0)
        return (rr(check));
    return (1);
}

int				ra(t_check *check)
{ /* BIEN */
    int         aux;

    if ((check->a) && (check->a->next != NULL))
    {
        aux = check->a->content;
        check->a = lst_del_first(check->a);
        ft_lstadd_back(&check->a, ft_lstnew(aux));
    }
    else
		return (print_error("Error en: ra\n"));
    print_list(check->a);
    return (0);
}

int				rb(t_check *check)
{   /* SF */
    int         aux;

    if ((check->b) && (check->b->next != NULL))
    {
       aux = check->b->content;
       check->b = lst_del_first(check->b);
       ft_lstadd_back(&check->b, ft_lstnew(aux));
    }
    else
		return (print_error("Error en: rb\n"));
    print_list(check->a);
    return (0);
}

int				rr(t_check *check)
{
    ra(check);
	rb(check);
	write(1, "rr\n", 3);
	return (0);
}
