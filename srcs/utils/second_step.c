/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:45:35 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/17 14:45:01 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	give_me_the_next_num(t_check *check, long a)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = check->b;
	while (aux)
	{
		i++;
		if (a == aux->content)
			break ;
		aux = aux->next;
	}
	return (i);
}

int	second_step2(t_check *check, long *a, int i)
{
	int count;

	count = 0;
	while (check->b->content != a[i])
	{
		count ++;
		rx(check, "rb", 'p');
	}
	if (check->b->content == a[i])
	{
		count ++;
		px(check, "pa", 'p');
	}
	return (count);
}

int	second_step3(t_check *check, long *a, int i)
{
	int count;

	count = 0;
	while (check->b->content != a[i])
	{
		count ++;
		rrx(check, "rrb", 'p');
	}
	if (check->b->content == a[i])
	{
		count ++;
		px(check, "pa", 'p');
	}
	return (count);
}

int	second_step(t_check *check, int len, long *a)
{
	int		i;
	int		z;
	int		count;

	count = 0;
	i = len - 1;
	while (i >= 0)
	{
		z = give_me_the_next_num(check, a[i]);
		if (z <= (ft_lstlen(check->b) / 2))
			second_step2(check, a, i);
		else
			second_step3(check, a, i);
		i--;
	}
	return (count);
}
