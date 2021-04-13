/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:32:37 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/09 18:33:51 by agutierr         ###   ########.fr       */
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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "error_msg.h"
#include "get_next_line.h"

int				sa(t_check *check);

#endif