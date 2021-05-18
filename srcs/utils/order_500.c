/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_500.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:16:44 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 20:43:32 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	first_step_500_2(t_check *check, int *i)
{
	while (check->a->content != check->hold_first)
		rx(check, "ra", 'p');
	if ((check->a->content) == (check->hold_first))
	{
		px(check, "pb", 'p');
		(*i)++;
	}
}

void	first_step_500_3(t_check *check, int *i)
{
	while (check->a->content != check->hold_second)
		rrx(check, "rra", 'p');
	if ((check->a->content) == (check->hold_second))
	{
		px(check, "pb", 'p');
		(*i)++;
	}
}

void	first_step_500(t_check *check, int len)
{
	int		i;
	int		multiplicador;

	multiplicador = 1;
	while (multiplicador <= 11)
	{
		i = 0;
		while (i < len / 11)
		{
			search_me_hold_500(check, len, multiplicador);
			if (check->first_position <= (len - check->second_position))
				first_step_500_2(check, &i);
			else
				first_step_500_3(check, &i);
		}
		multiplicador++;
	}
	if (len % 11 != 0)
		the_last_numbers_500(check, len);
}

void	the_last_numbers_500(t_check *check, int len)
{
	int		last_len;
	int		i;

	i = 0;
	last_len = len % 11;
	while (i < last_len)
	{
		if (check->a && check->a->next && check->b && check->b->next)
		{
			if ((check->a->content > check->a->next->content)
				&& (check->b->content < check->b->next->content))
				sx(check, "ss", 'p');
		}
		px(check, "pb", 'p');
		i++;
	}
}

void	order_500(t_check *check, long	*a)
{
	int		len;

	len = ft_lstlen(check->a);
	first_step_500(check, len);
	second_step_500(check, len, a);
}
