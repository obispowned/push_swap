/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:06:29 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 19:48:16 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	sx(t_check *check, char *line, char ps)
{
	if (strcmp((const char *)line, "sa") == 0)
	{
		if (ps == 'p')
			write(1, "sa\n", 3);
		return (sa(check));
	}
	else if (strcmp((const char *)line, "sb") == 0)
	{
		if (ps == 'p')
			write(1, "sb\n", 3);
		return (sb(check));
	}
	else if (strcmp((const char *)line, "ss") == 0)
	{
		if (ps == 'p')
			write(1, "ss\n", 3);
		return (ss(check));
	}
	return (1);
}

int	sa(t_check *check)
{
	long int	aux;

	if ((check->a) && (check->a->next != NULL))
	{
		aux = check->a->content;
		check->a->content = check->a->next->content;
		check->a->next->content = aux;
	}
	return (0);
}

int	sb(t_check *check)
{
	long int	aux;

	if ((check->b) && (check->b->next != NULL))
	{
		aux = check->b->content;
		check->b->content = check->b->next->content;
		check->b->next->content = aux;
	}
	return (0);
}

int	ss(t_check *check)
{
	sa(check);
	sb(check);
	return (0);
}
