# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 16:02:20 by agutierr          #+#    #+#              #
#    Updated: 2021/04/25 17:48:37 by agutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER			=	checker
PUSH_SWAP		=	push_swap

SRCS_CHECKER	=	./srcs/checker/*.c
SRCS_PUSH_SWAP	=	./srcs/push_swap/*.c
SRCS_UTILS		=	./srcs/utils/*.c

SANITIZE		=	-fsanitize=address

#########################################################

FLAGS			= 

GCC 			= gcc -g3

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
GRIS			= \033[1;30m
CYAN			= \033[0;36m
RESET			= \033[0m

$(CHECKER):
	$(GCC) $(FLAGS) $(SRCS_CHECKER) $(SRCS_UTILS) -o $(CHECKER)

$(PUSH_SWAP):
	$(GCC) $(FLAGS) $(SRCS_PUSH_SWAP) $(SRCS_UTILS) -o $(PUSH_SWAP)

all:	$(CHECKER) $(PUSH_SWAP)

fclean:	clean

clean :
	rm -f $(CHECKER) $(PUSH_SWAP)
	@echo "\033[0;31m[BORRANDO EJECUTABLE...]"

re:		fclean all

.PHONY:	clean all
