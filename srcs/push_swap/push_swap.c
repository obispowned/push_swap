/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:24:46 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/19 19:21:26 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	main(int	argc, char	**argv)
{
	t_check	check;
	char	**file;

	file = NULL;
	check.b = NULL;
	if (argc == 1)
		exit(1);
	if (argv[1] && strcmp(argv[1], "") == 0)
		print_exit("Error\n");
	if (check_args(argc, argv) == 1)
		return (print_error("Error\n"));
	if (argc == 2)
		check_params(file, argc, argv, &check);
	else
	{
		if (!(no_repeated_numbers(&argv[1])))
			return (print_error ("Error\n"));
		if (args(argc, argv, &check) == 1)
			return (1);
	}
	ia_order (&check);
	return (0);
}
