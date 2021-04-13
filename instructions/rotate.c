/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:13:03 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/11 16:13:57 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int				ra(t_check *check)
{
    int         aux;

    aux = check->a->content;
    check->a = lst_del_first(check->a);
    ft_lstadd_back(&check->a, ft_lstnew(aux));

}

int				rb(t_check *check)
{

}

int				rr(t_check *check)
{

}
