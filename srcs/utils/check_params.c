/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:26:28 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 19:35:05 by agutierr         ###   ########.fr       */
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

int		check_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != ' ') && (str[i] != '+') & (str[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}

void	check_params(char **file, int argc, char **argv, t_check *check)
{
	if (check_only_spaces(argv[1]) == 1)
		print_exit("Error\n");
	file = ft_split(argv[1], ' ');
	if (check_limit(file[0]) > 15)
		print_exit("Error\n");
	if (!(no_repeated_numbers(file)))
		print_exit("Error\n");
	one_arg(argc, file, check);
	double_kill(file);
}
