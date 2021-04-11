#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "./headers/push_swap.h"

void print_list(t_stack *stack)
{
	t_stack *aux;
	int		i;

	i = 0;
	aux = stack;
	while(aux->next != NULL)
	{
		printf("Elemento %d: %d\n", 1+i++, aux->content);
		aux = aux->next;
	}
	printf("Elemento %d: %d\n", 1+i++, aux->content);
	if (aux->next == NULL)
		printf("Fin de lista\n");
	else
		printf("Movidas\n");
}
int			isallnum(char *file)
{
	int		i;

	i = 0;
	while (file[i])
	{
		if (file[i] > '9' || file[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int			isallnum_and_spa(char *file)
{
	int		i;

	i = 0;
	while (file[i])
	{
		if ((file[i] > '9' || file[i] < '0') && (file[i] != ' '))
			return (1);
		i++;
	}
	return (0);
}

int			one_arg(int argc, char **file, t_check *check)
{
	int		i;

	i = 1;
	check->a = ft_lstnew(atoi(file[0])); /*file[0] xq ya spliteamos el argv*/
	while (file[i])
	{
		ft_lstadd_back(&check->a, ft_lstnew(atoi(file[i])));
		i++;
	}
	return (0);
}

int			args(int argc, char **argv, t_check *check)
{
	int		i;

	i = 2;
	if (isallnum(argv[1]) == 1)
		return(1);
	check->a = ft_lstnew(atoi(argv[1]));
	while (i < argc)
	{
		if (isallnum(argv[i]) == 1)
			return(1);
		ft_lstadd_back(&check->a, ft_lstnew(atoi(argv[i])));
		i++;
	}
	return (0);
}

int			check_args(int argc, char **argv)
{
	if ((argc == 2 && (isallnum_and_spa(argv[1]) == 1)) || (argc <= 1))
		return (1);
	return (0);
}

int         main(int argc, char **argv)
{
    t_check *check;
	char 	**file;

	file = NULL;
    check = (t_check *)malloc(sizeof(t_check));
	if (check_args(argc, argv) == 1)
		return (print_error("Error\n"));
	if (argc == 2) //si solo hay un argumento "23 24 56", hago el split y lo meto en nodos
	{
		file = ft_split(argv[1], ' ');
		one_arg(argc, file, check);
	}
	else		//si me llo pasan en vario argumentos 23 24 56, vamos anadiendo nodos por cada arg
	{
		if (args(argc, argv, check) == 1)
			return (print_error("Error\n"));
	}
	print_list(check->a);

	//system ("leaks push_swap");
	return (0);
}















    /*
    int		a;
	t_check	*check;

	if (argc <= 1)
		return (0);
	check = (t_check *)ft_memalloc(sizeof(t_check));
	a = args(argc, argv, check);
	if (a)
	{
		ERROR;
		if (check->ar)
			free_ar(check->ar, ft_lstlen(check->a));
		free(check);
		exit(0);
	}
	check->llen = ft_lstlen(check->a);
	if (check->llen >= 2 && check->llen <= 3)
	{
		sort_thre(check);
		free_mem(check);
	}
	if (sort_che(check->a, ascending))
		exit(0);
	sort(che, check->llen);
	free_mem(che);
    */

