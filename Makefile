NAME			= 	push_swap

SRCS			=	utils/*.c\
					main.c

#############################

FLAGS			= -Wall -Wall -Werror

GCC 			= gcc

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
GRIS			= \033[1;30m
CYAN			= \033[0;36m
RESET			= \033[0m

all:		$(NAME)

$(NAME):
			@echo "${RED}[...Haciendo CLEAN del a.out...]${RESET}"
			@rm -rf a.out
			@echo "${CYAN}[...Iniciando compilacion...]${GRIS}"
			$(GCC) $(SRCS) $(FLAGS) -o $(NAME)
			@echo "${RED}[.oOo.oOo.oOo.oOo.]${RESET}"
			@echo "${YELLOW}[ C O M P I L A O ]${RESET}"
			@echo "${PURPLE}[.oOo.oOo.oOo.oOo.]${RESET}"

fclean:	clean
	rm -f $(NAME)

clean :
	@echo "\033[0;31m[BORRANDO BASURA...]"
	$(RM) $(OBJS)

re:				fclean all

.PHONY:	clean all
