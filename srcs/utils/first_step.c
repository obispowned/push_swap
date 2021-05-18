/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:43:24 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 17:28:11 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	first_step2(t_check *check, int *i)
{
	int	count;

	count = 0;
	while (check->a->content != check->hold_first)
	{
		rx(check, "ra", 'p');
		count ++;
	}
	if ((check->a->content) == (check->hold_first))
	{
		count ++;
		px(check, "pb", 'p');
		(*i)++;
	}
	return (count);
}

int	first_step3(t_check *check, int *i)
{
	int	count;

	count = 0;
	while (check->a->content != check->hold_second)
	{
		rrx(check, "rra", 'p');
		count ++;
	}
	if ((check->a->content) == (check->hold_second))
	{
		count ++;
		px(check, "pb", 'p');
		(*i)++;
	}
	return (count);
}

int	first_step(t_check *check, int len)
{
	int		i;
	int		multiplicador;
	int		count;

	count = 0;
	multiplicador = 1;
	while (multiplicador <= 5)
	{
		i = 0;
		while (i < len / 5)
		{
			search_me_hold(check, len, multiplicador);
			if (check->first_position <= (len - check->second_position))
				count += first_step2(check, &i);
			else
				count += first_step3(check, &i);
		}
		multiplicador++;
	}
	if (len % 5 != 0)
		count += the_last_numbers(check, len);
	return (count);
}

int	the_last_numbers(t_check *check, int len)
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
			if ((check->a->content > check->a->next->content)
				&& (check->b->content < check->b->next->content))
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

void	order_100(t_check *check, long	*a)
{
	int		len;
	int		count;

	count = 0;
	len = ft_lstlen(check->a);
	if (!(is_this_order(check->a)))
	{
		count += first_step(check, len);
		count += second_step(check, len, a);
	}
}
