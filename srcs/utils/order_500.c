/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_500.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:16:44 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/17 16:52:56 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	second_step_500_2(t_check *check, long *a, int i)
{
	int	counter;

	counter = 0;
	while (check->b->content != a[i])
	{
		counter ++;
		rx(check, "rb", 'p');
	}
	if (check->b->content == a[i])
	{
		counter ++;
		px(check, "pa", 'p');
	}
	return (counter);
}

int	second_step_500_3(t_check *check, long *a, int i)
{
	int	counter;
	
	counter = 0;
	while (check->b->content != a[i])
	{
		counter ++;
		rrx(check, "rrb", 'p');
	}
	if (check->b->content == a[i])
	{
		counter ++;
		px(check, "pa", 'p');
	}
	return (counter);
}

int	second_step_500(t_check *check, int len, long *a)
{
	int		i;
	int		z;
	int		counter;

	counter = 0;
	i = len - 1;
	while (i >= 0)
	{
		z = give_me_the_next_num(check, a[i]);
		if (z <= (ft_lstlen(check->b) / 2))
			counter += second_step_500_2(check, a, i);
		else
			counter += second_step_500_3(check, a, i);
		i--;
	}
	return (counter);
}

int	smh2(t_check *check, int len, int multiplicador)
{
	t_stack *aux;
	int		i;

	i = 0;
	aux = check->a;
	while (aux)
	{
		i++;
		if (aux->position <= ((len / 11) * multiplicador))
		{
			check->hold_first = aux->content;
			break ;
		}
		aux = aux->next;
	}
	return (i);
}

int	smh3(t_check *check, int len, int multiplicador)
{
	t_stack *aux;
	int		j;
	int		z;

	z = 0;
	j = 0;
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
	return (z);
}

void	search_me_hold_500(t_check	*check, int len, int multiplicador)
{
	check->first_position = smh2(check, len, multiplicador);
	check->second_position = smh3(check, len, multiplicador);
}

int	first_step_500_2(t_check *check, int *i)
{
	int	counter;

	counter = 0;
	while (check->a->content != check->hold_first)
	{
		rx(check, "ra", 'p');
		counter ++;
	}
	if ((check->a->content) == (check->hold_first))
	{
		counter ++;
		px(check, "pb", 'p');
		(*i)++;
	}
	return(counter);
}

int	first_step_500_3(t_check *check, int *i)
{
	int	counter;

	counter = 0;
	while (check->a->content != check->hold_second)
	{
		rrx(check, "rra", 'p');
		counter ++;
	}
	if ((check->a->content) == (check->hold_second))
	{
		counter ++;
		px(check, "pb", 'p');
		i++;
	}
	return (counter);
}

int	first_step_500(t_check *check, int len)
{
	int		i;
	int		multiplicador;
	int		counter;

	counter = 0;
	multiplicador = 1;
	while (multiplicador <= 11)
	{
		i = 0;
		while (i < len / 11)
		{
			search_me_hold_500(check, len, multiplicador);
			if (check->first_position <= (len - check->second_position))
				counter += first_step_500_2(check, &i);
			else
				counter += first_step_500_3(check, &i);
		}
		multiplicador++;
	}
	if (len % 11 != 0)
		counter += the_last_numbers_500(check, len);
	return (counter);
}

int	the_last_numbers_500(t_check *check, int len)
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
			if ((check->a->content > check->a->next->content)
				&& (check->b->content < check->b->next->content))
			{
				sx(check, "ss", 'p');
				counter ++;
			}
		}
		px(check, "pb", 'p');
		counter ++;
		i++;
	}
	return (counter);
}

void	order_500(t_check *check, long	*a)
{
	int		len;
	int		counter;

	len = ft_lstlen(check->a);
	counter = first_step_500(check, len);
	counter += second_step_500(check, len, a);
}
