# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 16:02:20 by agutierr          #+#    #+#              #
#    Updated: 2021/05/18 19:34:28 by agutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP		=	push_swap
CHECKER			=	checker

SRCS_CHECKER	=	./srcs/checker/checker.c
SRCS_PUSH_SWAP	=	./srcs/push_swap/push_swap.c
SRCS_UTILS		=	./srcs/utils/args.c ./srcs/utils/first_step.c\
					./srcs/utils/ft_atoi.c ./srcs/utils/ft_split.c\
					./srcs/utils/ft_strcmp.c ./srcs/utils/ft_strlen.c\
					./srcs/utils/get_next_line_utils.c ./srcs/utils/get_next_line.c\
					./srcs/utils/is_digit.c ./srcs/utils/list_to_array.c\
					./srcs/utils/list.c ./srcs/utils/list2.c\
					./srcs/utils/order_3.c ./srcs/utils/order_500.c\
					./srcs/utils/order.c ./srcs/utils/printer.c\
					./srcs/utils/push.c ./srcs/utils/reverse_rotate.c\
					./srcs/utils/rotate.c ./srcs/utils/second_step.c\
					./srcs/utils/swap.c ./srcs/utils/validator.c\
					./srcs/utils/cleaner.c ./srcs/utils/search_me_hold.c\
					./srcs/utils/search_me_hold_500.c ./srcs/utils/check_params.c\
					./srcs/utils/second_step_500.c ./srcs/utils/stdin.c\

SANITIZE		=	-fsanitize=address

#########################################################

CFLAGS			= -Werror -Wextra -Wall -g3

GCC 			= gcc

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
GRIS			= \033[1;30m
CYAN			= \033[0;36m
RESET			= \033[0m

$(CHECKER):
	$(GCC) $(CFLAGS) $(SRCS_CHECKER) $(SRCS_UTILS) -o $(CHECKER)

$(PUSH_SWAP):
	$(GCC) $(CFLAGS) $(SRCS_PUSH_SWAP) $(SRCS_UTILS) -o $(PUSH_SWAP)

all:	$(CHECKER) $(PUSH_SWAP)

fclean:	clean

clean :
	rm -f $(CHECKER) $(PUSH_SWAP)
	@echo "\033[0;31m[BORRANDO EJECUTABLE...]\033[1;32m"

re:		fclean all

.PHONY:	clean all fclean re
