/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:44:45 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/24 15:07:31 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void print_list(t_stack *stack)
{
	t_stack *aux;
	int		i;

	i = 0;
	aux = stack;
	while(aux->next != NULL)
	{
		printf("Elemento %d: %d\n", 1+i++, (int)aux->content);
		aux = aux->next;
	}
	printf("Elemento %d: %d\n", 1+i++, (int)aux->content);
	if (aux->next == NULL)
		printf("Fin de lista\n");
	else
		printf("Movidas\n");
}

int	print_error(const char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

void	print_sinmas(const char *str)
{
	write(1, str, ft_strlen(str));
}
