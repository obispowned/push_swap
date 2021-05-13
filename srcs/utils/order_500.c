/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_500.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:16:44 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/13 22:06:08 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int		second_step_500(t_check *check, int len, long *a)
{
	t_stack	*stack;
	int		i, z;
	int		counter;

	counter = 0;
	stack = check->b;
	i = len - 1;
	while (i >= 0)
	{
		stack = check->b;
		z = give_me_the_next_num(check, a[i]);
		if (z <= (ft_lstlen(check->b)/2))
		{
			while (check->b->content != a[i])
			{
				counter ++;
				rx(check, "rb");
			}
			if (check->b->content == a[i])
			{
				counter ++;
				pa(check);
			}
		}
		else
		{
			while (check->b->content != a[i])
			{
				counter ++;
				rrx(check, "rrb");
			}
			if (check->b->content == a[i])
			{
				counter ++;
				pa(check);
			}
		}
		i--;
	}
	return (counter);
}

void		search_me_hold_500(t_check	*check, int len, int multiplicador)
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
		if (aux->position <= ((len / 11) * multiplicador))
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
		if (aux->position <= ((len / 11) * multiplicador))
		{
			check->hold_second = aux->content;
			z = j;
		}
		aux = aux->next;
	}
	check->first_position = i;
	check->second_position = z;
}

int		first_step_500(t_check *check, int len)
{ //meto los todos los chunks a B
	int 	i;
	int		multiplicador;
	int		counter;

	counter = 0;
	multiplicador = 1;
	while (multiplicador <= 11)
	{
		i = 0;
		while (i < len/11)
		{
			search_me_hold_500(check, len, multiplicador);
			if (check->first_position <= (len - check->second_position))
			{
				while(check->a->content != check->hold_first)
				{
					rx(check, "ra");
					counter ++;
				}
				if ((check->a->content) == (check->hold_first))
				{
					counter ++;
					pb(check);
					i++;
				}
			}
			else
			{
				while(check->a->content != check->hold_second)
				{
					rrx(check, "rra");
					counter ++;
				}
				if ((check->a->content) == (check->hold_second))
				{
					counter ++;
					pb(check);
					i++;
				}
			}
		}
		multiplicador++;
	}
	if (len % 11 != 0)
		counter += the_last_numbers_500(check, len);
	return (counter);
}

int			the_last_numbers_500(t_check *check, int len)
{
	int		last_len;
	int		i;
	int		counter;

	i = 0;
	last_len = len % 11;
	counter = 0;
	while (i < last_len)
	{
		if (check->a && check->a->next && check->b && check->b->next)
		{
			if ((check->a->content > check->a->next->content) &&
			(check->b->content < check->b->next->content))
			{
				ss(check);
				counter ++;
			}
		}
		pb(check);
		counter ++;
		i++;
	}
	return (counter);
}

void		order_500(t_check *check, long	*a)
{
	t_stack	*stack;
	int		len;
	int		counter;

	stack = check->a;
	len = ft_lstlen(check->a);
	counter = first_step_500(check, len);
	counter += second_step_500(check, len, a);
	printf("| Instrucciones utilizadas: %d |\n", counter);
}
