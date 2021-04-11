/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:08 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/11 18:48:59 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int				pa(t_check *check)
{
	int	aux;

	if (check->b)
	{
		aux = check->b->content;
		lst_del_first(check->b);
		ft_lstadd_front(&check->a, ft_lstnew(aux));
		write(1, "pa\n", 3);
		return (0);
	}
	return (1);
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
		return (0);
	}
	return (1);
}
