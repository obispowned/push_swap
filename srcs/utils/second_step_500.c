/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step_500.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:49:41 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 20:41:18 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	second_step_500_2(t_check *check, long *a, int i)
{
	while (check->b->content != a[i])
		rx(check, "rb", 'p');
	if (check->b->content == a[i])
		px(check, "pa", 'p');
}

void	second_step_500_3(t_check *check, long *a, int i)
{
	while (check->b->content != a[i])
		rrx(check, "rrb", 'p');
	if (check->b->content == a[i])
		px(check, "pa", 'p');
}

void	second_step_500(t_check *check, int len, long *a)
{
	int		i;
	int		z;

	i = len - 1;
	while (i >= 0)
	{
		z = give_me_the_next_num(check, a[i]);
		if (z <= (ft_lstlen(check->b) / 2))
			second_step_500_2(check, a, i);
		else
			second_step_500_3(check, a, i);
		i--;
	}
}
