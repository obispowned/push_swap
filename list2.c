/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:32:41 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/09 18:32:41 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void		ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (lst && del)
	{
		(*del)(lst->content);
		free(lst);
	}
}

void			ft_lstclear(t_stack **lst, void (*del)(void*))
{
	t_stack		*aux;

	if (lst)
	{
		while (*lst)
		{
			aux = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = aux;
		}
	}
}

void		ft_lstiter(t_stack *lst, void (*f)(void *))
{
	t_stack	*pointer;

	pointer = lst;
	if (lst)
	{
		while (pointer)
		{
			f(pointer->content);
			pointer = pointer->next;
		}
	}
}

t_stack		*ft_lstmap(t_stack *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_stack	*pointer;
	t_stack	*aux;

	if (lst == NULL || f == NULL)
		return (NULL);
	pointer = NULL;
	while (lst != NULL)
	{
		if ((aux = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&pointer, del);
			return (NULL);
		}
		ft_lstadd_back(&pointer, aux);
		lst = lst->next;
	}
	return (pointer);
}