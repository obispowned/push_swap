/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:25:17 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/25 20:29:37 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*comprobar que no salga del rango de int con long y atol*/
/*comprobar que no haya numeros duplicados*/
int         main(int argc, char **argv)
{
    t_check *check;
	char 	**file;

	file = NULL;
    check = (t_check *)malloc(sizeof(t_check));
	check->b = NULL;
	if (check_args(argc, argv) == 1)
		return (print_error("Error1\n"));
	if (argc == 2) //si solo hay un argumento "23 24 56", hago el split y lo meto en nodos
	{
		file = ft_split(argv[1], ' ');
		if(!(no_repeated_numbers(file)))
			return(print_error("Error2\n"));
		one_arg(argc, file, check);
	}
	else		//si me llo pasan en vario argumentos 23 24 56, vamos anadiendo nodos por cada arg
	{
		if(!(no_repeated_numbers(&argv[1])))
			return(print_error("Error7\n"));
		if (args(argc, argv, check) == 1)
			return (print_error("Error3\n"));
	}
	print_list(check->a, 'A');
	print_list(check->b, 'B');
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

