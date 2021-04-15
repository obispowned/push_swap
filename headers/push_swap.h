/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:32:37 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/14 14:01:22 by agutierr         ###   ########.fr       */
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
int				ra(t_stack **a);
int				rb(t_stack **b);
int				rr(t_check *check);
int				rx(t_check *check, char *line);
/***/
int				rrx(t_check *check, char *line);
int				rra(t_stack **a);
int				rrb(t_check *check);
int				rrr(t_check *check);

/*
*
*/

#endif
