/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_me_hold.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:47:59 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 17:25:12 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	smh2(t_check *check, int len, int multiplicador)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = check->a;
	while (aux)
	{
		i++;
		if (aux->position <= ((len / 5) * multiplicador))
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
	t_stack	*aux;
	int		j;
	int		z;

	z = 0;
	j = 0;
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
	return (z);
}

void	search_me_hold(t_check	*check, int len, int multiplicador)
{
	check->first_position = smh2(check, len, multiplicador);
	check->second_position = smh3(check, len, multiplicador);
}
