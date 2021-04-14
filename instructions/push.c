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
	int	aux;

	if (check->b)
	{
		aux = check->b->content;
		lst_del_first(check->b);
		ft_lstadd_front(&check->a, ft_lstnew(aux));
		write(1, "pa\n", 3);
	}
	else
		return (print_error("Error en: pa\n"));
	print_list(check->a);
	return (0);
}

int				pb(t_check *check)
{
	int	aux;

	if (check->a)
	{
		aux = check->a->content;
		lst_del_first(check->a);
		ft_lstadd_front(&check->b, ft_lstnew(aux));
		write(1, "pb\n", 3);
	}
	else
		return (print_error("Error en: pa\n"));
	print_list(check->a);
	return (0);
}
