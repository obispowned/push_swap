/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:47:41 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/15 17:50:50 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

t_stack	*lst_del_first(t_stack *stack)
{
	t_stack	*aux;

	if (stack != NULL)
	{
		aux = stack;
		stack = stack->next;
		free(aux);
	}
	else
		print_error("Error, Lista vacia\n");
	return (stack);
}

void	lst_del_last(t_stack *stack)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (stack != NULL)
	{
		aux = stack;
		tmp = stack;
		while (aux->next != NULL)
		{
			tmp = aux;
			aux = aux->next;
		}
		if (aux == stack)
			stack = NULL;
		else
			tmp->next = NULL;
		free (aux);
	}
}
