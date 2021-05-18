/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step_500.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:49:41 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 16:49:44 by agutierr         ###   ########.fr       */
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
