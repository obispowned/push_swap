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
		return (rra(check));
	else if (strcmp((const char *)line, "rrb") == 0)
		return (rrb(check));
    else if (strcmp((const char *)line, "rrr") == 0)
        return (rrr(check));
	return (1);
}

int				rra(t_check *check)
{
	int         aux;

	aux = (ft_lstlast(check->a))->content;
	lst_del_last(check->a);
	ft_lstadd_front(&check->a, ft_lstnew(aux));
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
