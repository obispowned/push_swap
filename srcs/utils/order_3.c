/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:00:58 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/15 18:15:54 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	order_3_c213(t_check *check)
{
	sx(check, "sa");
	return (1);
}

int	order_3_c321(t_check *check)
{
	sx(check, "sa");
	rrx(check, "rra");
	return (2);
}

int	order_3_c312(t_check *check)
{
	rx(check, "ra");
	return (1);
}

int	order_3_c132(t_check *check)
{
	sx(check, "sa");
	rx(check, "ra");
	return (2);
}

int	order_3_c231(t_check *check)
{
	rrx(check, "rra");
	return (1);
}
