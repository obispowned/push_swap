/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:25:17 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/17 13:50:55 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_check	*check;
	char	**file;

	file = NULL;
	check = (t_check *)malloc(sizeof(t_check));
	check->b = NULL;
	if (check_args(argc, argv) == 1)
		return (print_error("Error\n"));
	if (argc == 2)
	{
		file = ft_split(argv[1], ' ');
		if (!(no_repeated_numbers(file)))
			return (print_error("Error\n"));
		one_arg (argc, file, check);
	}
	else
	{
		if (!(no_repeated_numbers(&argv[1])))
			return (print_error("Error\n"));
		if (args(argc, argv, check) == 1)
			return (print_error("Error\n"));
	}
	if (check_stdin (check) == 1)
		return (1);
	return (0);
}
