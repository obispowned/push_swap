/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:32:39 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/11 18:43:08 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_stack		*ft_lstnew(int content)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_stack **alst, t_stack *new)
{
	t_stack	*aux;

	aux = *alst;
	*alst = new;
	new->next = aux;
}

void			ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack		*p;

	p = ft_lstlast(*alst);
	if (new)
	{
		if (*alst != NULL)
		{
			p->next = new;
			new->next = NULL;
		}
		else
		{
			*alst = new;
			new->next = NULL;
		}
	}
}

int			ft_lstlen(t_stack *lst)
{
	int		c;
	t_stack	*tmp;

	c = 0;
	tmp = lst;
	while (lst != NULL)
	{
		c++;
		lst = lst->next;
	}
	lst = tmp;
	return (c);
}

t_stack		*ft_lstlast(t_stack *lst)
{
	t_stack	*p;

	p = lst;
	if (p)
	{
		while (p->next != NULL)
			p = p->next;
		return (p);
	}
	else
		return (0);
}

void		lst_del_first(t_stack *stack) /* falta comprobacion */
{
	t_stack *aux;

	aux = stack->next;
	stack->content = 0;
	free(stack);
	stack = aux;
}
