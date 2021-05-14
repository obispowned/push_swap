/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:43:24 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/14 17:30:58 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"


void		tell_me_the_positions(t_stack	**stack, long *a)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	while (aux)
	{
		i = 0;
		while (a[i] != aux->content)
			i++;
		if (a[i] == aux->content)
			aux->position = i + 1;
		aux = aux->next;
	}
}

void		search_me_hold(t_check	*check, int len, int multiplicador)
{		//esto me busca hold up y hold down
	t_stack	*aux;
	int		i, j, z;

	i = 0;
	j = 0;
	z = 0;
	aux = check->a;
	while (aux)
	{
		i++;
		if (aux->position <= ((len / 5) * multiplicador))
		{
			check->hold_first = aux->content;
			break;
		}
		aux = aux->next;
	}
	aux = check->a;
	while (aux)
	{
		j++;
		if (aux->position <= ((len / 5) * multiplicador))
		{
			check->hold_second = aux->content;
			z = j;
		}
		aux = aux->next;
	}
	check->first_position = i;
	check->second_position = z;
}

int		first_step(t_check *check, int len)
{ //meto los todos los chunks a B
	int 	i;
	int		multiplicador;
	int		count;

	count = 0;
	multiplicador = 1;
	while (multiplicador <= 5)
	{
		i = 0;
		while (i < len/5)
		{
			search_me_hold(check, len, multiplicador);
			if (check->first_position <= (len - check->second_position))
			{
				while(check->a->content != check->hold_first)
				{
					rx(check, "ra");
					count ++;
				}
				if ((check->a->content) == (check->hold_first))
				{
					count ++;
					pb(check);
					i++;
				}
			}
			else
			{
				while(check->a->content != check->hold_second)
				{
					rrx(check, "rra");
					count ++;
				}
				if ((check->a->content) == (check->hold_second))
				{
					count ++;
					pb(check);
					i++;
				}
			}
		}
		multiplicador++;
	}
	if (len % 5 != 0)
		count += the_last_numbers(check, len);
	return (count);
}

int			the_last_numbers(t_check *check, int len)
{
	int		last_len;
	int		i;
	int		count;

	i = 0;
	last_len = len % 5;
	count = 0;
	while (i < last_len)
	{
		if (check->a && check->a->next && check->b && check->b->next)
		{
			if ((check->a->content > check->a->next->content) &&
			(check->b->content < check->b->next->content))
			{
				ss(check);
				count ++;
			}
		}
		pb(check);
		count ++;
		i++;
	}
	return (count);
}

void		order_100(t_check *check, long	*a)
{
	t_stack	*stack;
	int		len;
	int		count;

	stack = check->a;
	len = ft_lstlen(check->a);
	count = first_step(check, len);
	count += second_step(check, len, a);
	printf("| Instrucciones utilizadas: %d |\n", count);
}
