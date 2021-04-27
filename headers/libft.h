/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:15:52 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/27 17:58:48 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef struct		s_stack
{
	long			content; //dato
	struct s_stack	*next; //puntero al siguiente nodo
}					t_stack;

typedef struct		s_check
{
	t_stack			*a;
	t_stack			*b;

	int				print_stacks;
	int				do_write;
	int				stack_len;
	long			quarter;
	long			median;
	long			three_quarters;

	long			biggest;
	int				big_rotate;
	int				big_rrotate;
	int				big_flag;

	long			smallest;
	int				small_rotate;
	int				small_rrotate;
	int				small_flag;

	int				after_rotate;
}					t_check;

/*
*	Libft
*/

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			isallnum(char *file);

long long	ft_atol(const char *str);
int			isallnum_and_spa(char *file);
int			is_spa(char *file);
int			isallnum_and_spa_and_minus(char *file);
int			isallnum_and_minus(char *file);
int			no_repeated_numbers(char **arr);
int			str_array_length(char **arr);
void		free_array(char **arr);

/*
* list.c
*/
t_stack		*ft_lstnew(int content);
void	    ft_lstadd_front(t_stack **alst, t_stack *new);
void		ft_lstadd_back(t_stack **alst, t_stack *new);
int			ft_lstlen(t_stack *lst);
t_stack		*ft_lstlast(t_stack **lst);
t_stack		*lst_del_first(t_stack *stack);
void		lst_del_last(t_stack *stack);


#endif
