/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:59:51 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/26 19:03:51 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

long		*order_array(long	*a, int nelementos)
{		//ORDENA EL ARRAY CON N ELEMENTOS
	int i,j;                //Variables contadoras del ciclo.
	long temp = 0;             //Variable temporal.

	i = 1;
	while (i < nelementos)
	{
		j = 0;
		while (j < nelementos-i) // for(j=0; j < Nelementos-i; j++) es menor y no menor igual
		{
			if (a[j] > a[j+1])//Condicion mayor-menor
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
			j++;
		}
		i++;
	}
	return (a);
}

long		*fill_me_array(t_check *check)
{		//ME TRAE UN ARRAY DE LONG CON LOS NUMEROS DE LA LISTA A Y LO ORDENA
	t_stack	*stack;
	long	*a;
	int		i;

	stack = check->a;
	i = 0;
	a = (long *)malloc(sizeof(long) * (ft_lstlen(check->a)));
	while (i < ft_lstlen(check->a) && stack != NULL)
	{
		a[i] = stack->content;
		stack = stack->next;
		i++;
	}
	a = order_array(a, ft_lstlen(check->a));
	return (a);
}
