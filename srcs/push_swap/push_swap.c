/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:24:46 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 17:56:00 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	check_params2(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (ft_strlen(file[i]) > 10)
			return (0);
		i++;
	}
	return (1);
}

void	check_params(char **file, int argc, char **argv, t_check *check)
{
	file = ft_split(argv[1], ' ');
	if (check_limit(file[0]) > 9)
		print_exit("Error\n");
	if (!(no_repeated_numbers(file)))
		print_exit("Error\n");
	one_arg(argc, file, check);
	double_kill(file);
}

int	main(int	argc, char	**argv)
{
	t_check	*check;
	char	**file;

	file = NULL;
	check = (t_check *)malloc(sizeof(t_check));
	check->b = NULL;
	if (check_args(argc, argv) == 1)
		return (print_error("Error\n"));
	if (argc == 2)
		check_params(file, argc, argv, check);
	else
	{
		if (!(no_repeated_numbers(&argv[1])))
			return (print_error ("Error\n"));
		if (args(argc, argv, check) == 1)
			return (print_error("Error\n"));
	}
	ia_order (check);
	return (0);
}
