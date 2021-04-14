/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:32:39 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/14 16:30:01 by agutierr         ###   ########.fr       */
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

void		ft_lstadd_front(t_stack **alst, t_stack *new)
{
	t_stack	*aux;

	aux = *alst;
	*alst = new;
	new->next = aux;
}

void		ft_lstadd_back(t_stack **alst, t_stack *new)
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

t_stack		*lst_del_first(t_stack *stack) /* falta comprobacion */
{
	t_stack *aux;

	if (stack != NULL)
	{
		aux = stack;
		stack = stack->next;
		free(aux);
	}
	else
		print_error("Lista vacia");
	return (stack);
}

void		lst_del_last(t_stack *stack) /* falta comprobacion */
{
	t_stack *aux;
	t_stack *tmp;

	if (stack != NULL)
	{
		aux = stack;
		tmp = stack;
		while(aux->next != NULL)
        {
            tmp = aux;
            aux = aux->next;
        }
		if(aux == stack)
            stack = NULL;
        else
            tmp->next = NULL;
        free(aux);
	}
}
