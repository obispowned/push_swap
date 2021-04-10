/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:32:19 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/10 14:15:14 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERROR ft_putendl_fd("Error", 5);
# define KO ft_putendl_fd("KO", 2);
# define OK ft_putendl_fd("OK", 2);
# define SA ft_putendl_fd("sa", 1);
# define SB ft_putendl_fd("sb", 1);
# define SS ft_putendl_fd("ss", 1);
# define PA ft_putendl_fd("pa", 1);
# define PB ft_putendl_fd("pb", 1);
# define RA ft_putendl_fd("ra", 1);
# define RB ft_putendl_fd("rb", 1);
# define RR ft_putendl_fd("rr", 1);
# define RRA ft_putendl_fd("rra", 1);
# define RRB ft_putendl_fd("rrb", 1);
# define RRR ft_putendl_fd("rrr", 1);

int         print_error(const char *str);


#endif
