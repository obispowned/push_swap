/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:00:54 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/14 14:00:55 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

int			one_arg(int argc, char **file, t_check *check)
{
	int		i;
//cambiar atol por atol
	i = 1;
	check->a = ft_lstnew(atol(file[0])); /*file[0] xq ya spliteamos el argv*/
	while (file[i])
	{
		ft_lstadd_back(&check->a, ft_lstnew(atol(file[i])));
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
	check->a = ft_lstnew(atol(argv[1]));
	while (i < argc)
	{
		if (isallnum(argv[i]) == 1)
			return(1);
		ft_lstadd_back(&check->a, ft_lstnew(atol(argv[i])));
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

int		check_stdin(t_check *check)
{
	int		size;
	char 	*line;

	while ((size = get_next_line(0, &line)) > 0)
	{			//sin los else me escribe directo
		if ((strcmp((const char *)line, "sa") == 0) ||
		(strcmp((const char *)line, "sb") == 0) ||
		(strcmp((const char *)line, "ss") == 0))
			sx(check, line);
		else if ((strcmp((const char *)line, "ra") == 0) ||
		(strcmp((const char *)line, "rb") == 0) ||
		(strcmp((const char *)line, "rr") == 0))
			rx(check, line);
		else if ((strcmp((const char *)line, "rra") == 0) ||
		(strcmp((const char *)line, "rrb") == 0) ||
		(strcmp((const char *)line, "rrr") == 0))
			rrx(check, line);
		else if ((strcmp((const char *)line, "pa") == 0) ||
		(strcmp((const char *)line, "pb") == 0))
			px(check, line);
		else if (strcmp((const char *)line, "") == 0)
			break;
		else
			return (print_error("Error\n"));
		free(line);
		print_list(check->a);
	}
	return (0);
}

/*comprobar que no salga del rango de int con long y atol*/
/*comprobar que no haya numeros duplicados*/
int         main(int argc, char **argv)
{
    t_check *check;
	char 	**file;
	char 	*scanner = malloc(sizeof(char) * 3);

	scanner[2] = '\0';
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
	if (check_stdin(check) == 1)
		return(1);
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

