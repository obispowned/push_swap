/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:24:46 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/26 18:08:13 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int		main(int	argc, char	**argv)
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
	ia_order(check);
	print_list(check->a, 'A');
	print_list(check->b, 'B');
	return (0);
}
