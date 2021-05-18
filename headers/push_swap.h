/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:32:37 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 20:42:41 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdarg.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "msg.h"
# include "get_next_line.h"

# define CYAN	"\x1B[36m"
# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE	"\x1B[34m"
# define MAG	"\x1B[35m"
# define WHITE	"\x1B[37m"
# define RESET	"\x1B[0m"
# define CLR	"\e[1;1H\e[?25l"

int				sx(t_check *check, char *line, char ps);
int				sa(t_check *check);
int				sb(t_check *check);
int				ss(t_check *check);

int				px(t_check *check, char *line, char ps);
int				pa(t_check *check);
int				pb(t_check *check);

int				rx(t_check *check, char *line, char ps);
int				ra(t_check *check);
int				rb(t_check *check);
int				rr(t_check *check);

int				rrx(t_check *check, char *line, char ps);
int				rra(t_check *check);
int				rrb(t_check *check);
int				rrr(t_check *check);

void			order_500(t_check *check, long	*a);
void			order_100(t_check *check, long *a);
void			order_5(t_check *check, long *a);
void			order_4(t_check *check, long *a);
int				order_3(t_check *check);
void			order_2(t_check *check);
void			ia_order(t_check	*check);

long			*order_array(long	*a, int nelementos);
long			*fill_me_array(t_check *check);
void			double_print(char **str);
int				one_arg(int argc, char **file, t_check *check);
int				args(int argc, char **argv, t_check *check);
int				check_args(int argc, char **argv);
char			*check_OK_KO(t_stack **stack);
int				check_stdin(t_check *check);

void			tell_me_the_positions(t_stack	**stack, long *a);
int				first_step(t_check *check, int len);
int				the_last_numbers(t_check *check, int len);

int				is_this_order(t_stack *stack);
int				give_me_the_next_num(t_check *check, long a);
int				second_step(t_check *check, int len, long *a);
int				second_step2(t_check *check, long *a, int i);
int				second_step3(t_check *check, long *a, int i);

void			search_me_hold(t_check	*check, int len, int multiplicador);
int				smh2(t_check *check, int len, int multiplicador);
int				smh3(t_check *check, int len, int multiplicador);
void			search_me_hold_500(t_check	*check, int len, int multiplicador);
int				smh2_500(t_check *check, int len, int multiplicador);
int				smh3_500(t_check *check, int len, int multiplicador);

void			first_step_500(t_check *check, int len);
void			the_last_numbers_500(t_check *check, int len);
void			second_step_500(t_check *check, int len, long *a);

int				order_3_c213(t_check *check);
int				order_3_c321(t_check *check);
int				order_3_c312(t_check *check);
int				order_3_c132(t_check *check);
int				order_3_c231(t_check *check);

void			tell_me_the_positions(t_stack	**stack, long *a);
void			double_kill(char **str);

int				check_limit(char *str);
void			check_params(char **file, int argc, char **argv, t_check *check);

#endif
