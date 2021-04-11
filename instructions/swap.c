/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:06:29 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/11 16:10:54 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int				sa(t_check *check)
{
	long int	aux;

	if ((check->a) && (check->a->next != NULL))
	{
		aux = check->a->content;
		check->a->content = check->a->next->content;
		check->a->next->content = aux;
		write(1, "sa\n", 3); /* CON SS SALE ESTO*/
	}
	else
		printf("Error en: sa\n");
	return(0);
}

int				sb(t_check *check)
{
	long int	aux;

	if ((check->b) && (check->b->next != NULL))
	{
		aux = check->b->content;
		check->b->content = check->b->next->content;
		check->b->next->content = aux;
		write(1, "sb\n", 3); /* CON SS SALE ESTO*/
	}
	else
		printf("Error en: sb\n");
	return(0);
}

int				ss(t_check *check)
{
	sa(check);
	sb(check);
	write(1, "ss\n", 3);
	return (0);
}
