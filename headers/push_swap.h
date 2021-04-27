/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:32:37 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/27 20:03:54 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CYAN	"\x1B[36m"
# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE	"\x1B[34m"
# define MAG	"\x1B[35m"
# define WHITE	"\x1B[37m"
# define RESET	"\x1B[0m"
# define CLR	"\e[1;1H\e[?25l"


#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "msg.h"
#include "get_next_line.h"

/*
*	INSTRUCTIONS
*/
int				sa(t_check *check);
int				sb(t_check *check);
int				ss(t_check *check);
int				sx(t_check *check, char *line);
/***/
int				px(t_check *check, char *line);
int				pa(t_check *check);
int				pb(t_check *check);
/***/
int				ra(t_check *check);
int				rb(t_check *check);
int				rr(t_check *check);
int				rx(t_check *check, char *line);
/***/
int				rrx(t_check *check, char *line);
int				rra(t_check *check);
int				rrb(t_check *check);
int				rrr(t_check *check);

/*
*	ALGORYTMS
*/
void			order_100(t_check *check);
void			order_5(t_check *check);
void			order_4(t_check *check);
void			order_3(t_check *check);
void			order_2(t_check *check);
void			ia_order(t_check	*check);

/*
*
*/
long			*order_array(long	*a, int nelementos);
long			*fill_me_array(t_check *check);
void			double_print(char **str);
int				one_arg(int argc, char **file, t_check *check);
int				args(int argc, char **argv, t_check *check);
int				check_args(int argc, char **argv);
char			*check_OK_KO(t_stack **stack);
int				check_stdin(t_check *check);

void			sort_array(long *array, int len);
void			find_mid(t_check *check, t_stack *stack, char stack_name);
void			mid(t_check *check, char stack_name);
void			push_mid(t_check *check, int split);

void			find_biggest(t_check *check, char stack_name);
void			find_biggest_smallest(t_check *check, char stack_name);
void			find_smallest(t_check *check, char stack_name);

void			moves_to_start(t_check *check, char stack_name, int flag);
void			moves_to_end(t_check *check, char stack_name, int flag);
void			moves_smallest(t_check *check, char stack_name);
void			moves_biggest(t_check *check, char stack_name);
void			find_moves(t_check *check, char stack_name);
void			push_big_small(t_check *check, t_stack *stack, t_stack *stack_end);

#endif
