/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:15:52 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/10 13:26:08 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef struct		s_stack
{
	int				content; //dato
	struct s_stack	*next; //puntero al siguiente nodo
}					t_stack;

typedef struct		s_check
{
	t_stack			*a;
	t_stack			*b;
}					t_check;


int			ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
/*
* list.c
*/
t_stack		*ft_lstnew(int content);
void	    ft_lstadd_front(t_stack **alst, t_stack *new);
void		ft_lstadd_back(t_stack **alst, t_stack *new);
int			ft_lstlen(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);

/*
* list2.c
*/
/*void		ft_lstdelone(t_stack *lst, void (*del)(void*));
void		ft_lstclear(t_stack **lst, void (*del)(void*));
void		ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack		*ft_lstmap(t_stack *lst, void *(*f)(void *),
		void (*del)(void *));*/

#endif
