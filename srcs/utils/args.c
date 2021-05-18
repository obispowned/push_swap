/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:29:53 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 17:56:16 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	check_limit(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			count++;
		i++;
	}
	return (count);
}

int	one_arg(int argc, char **file, t_check *check)
{
	int			i;
	long long	j;

	(void)argc;
	if (check_limit(file[0]) > 9)
		return (print_error("Error\n"));
	j = atol(file[0]);
	i = 1;
	if (j > 2147483647 || j < -2147483648)
		return (print_error("Error\n"));
	check->a = ft_lstnew (j);
	while (file[i])
	{
		ft_lstadd_back(&check->a, ft_lstnew(atol(file[i])));
		i++;
	}
	return (0);
}

char	**arg_malloc(char **argv, int argc)
{
	char		**check_nums;

	check_nums = malloc (sizeof(char *) * argc);
	check_nums[0] = ft_strdup(argv[1]);
	return (check_nums);
}

int	args(int argc, char **argv, t_check *check)
{
	int			i;
	long long	j;

	i = 2;
	if (isallnum_and_minus(argv[1]) == 1)
		return (1);
	if (check_limit(argv[1]) > 9)
		return (print_error("Error\n"));
	j = atol(argv[1]);
	if (j > 2147483647 || j < -2147483648)
		return (print_error("Error\n"));
	check->a = ft_lstnew(j);
	while (i < argc)
	{
		if (isallnum_and_minus(argv[i]) == 1)
			return (1);
		if (check_limit(argv[i]) > 9)
			return (print_error("Error\n"));
		j = atol(argv[i]);
		if (j > 2147483647 || j < -2147483648)
			return (print_error("Error\n"));
		ft_lstadd_back(&check->a, ft_lstnew(j));
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if ((argc == 2 && (isallnum_and_spa_and_minus(argv[1]) == 1))
		|| (argc <= 1))
		return (1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' && ((!argv[i][j + 1])
				|| (argv[i][j + 1] < '0' || argv[i][j + 1] > '9')))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
