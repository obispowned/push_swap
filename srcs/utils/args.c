/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:29:53 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/14 16:50:47 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int			one_arg(int argc, char **file, t_check *check)
{
	int	  	  i;
	long long j;

	j = atol(file[0]);
	i = 1;
	if (j > 2147483647 || j < -2147483648)
	{
		printf("Tamano demasiado grande");
		return (1);
	}
	check->a = ft_lstnew(j); /*file[0] xq ya spliteamos el argv*/
	while (file[i])
	{
		ft_lstadd_back(&check->a, ft_lstnew(atol(file[i])));
		i++;
	}
	return (0);
}

void		double_print(char **str)
{
	int i;

	i = 1;
	while (str[i])
	{
		printf("%s\n",str[i]);
		i++;
	}
}

int			args(int argc, char **argv, t_check *check)
{
	int		i;
	long long j;
	char	**check_nums;

	check_nums = malloc(sizeof(char*) * argc);
	check_nums[0] = ft_strdup(argv[1]);
	i = 2;
	if (isallnum_and_minus(argv[1]) == 1)
		return(1);
	j = atol(argv[1]);
	if (j > 2147483647 || j < -2147483648)
	{
		printf("Tamano demasiado grande");
		return (1);
	}
	check->a = ft_lstnew(j);
	while (i < argc)
	{
		check_nums[i-1] = ft_strdup(argv[i]);
		if (isallnum_and_minus(argv[i]) == 1)
			return(1);
		j = atol(argv[i]);
		if (j > 2147483647 || j < -2147483648)
		{
			printf("Tamano demasiado grande");
			return (1);
		}
		ft_lstadd_back(&check->a, ft_lstnew(j));
		i++;
	}
	return (0);
}

int			check_args(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if ((argc == 2 && (isallnum_and_spa_and_minus(argv[1]) == 1)) || (argc <= 1))
		return (1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' && ((!argv[i][j+1]) || (argv[i][j+1] < '0' || argv[i][j+1] > '9')))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	*check_OK_KO(t_stack **stack)
{	/*COMPRUEBA AL FINAL DE CHECKER SI TODOS LOS NUMEROS ESTAN COLOCADOS*/
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	if (tmp)
	{
		i = tmp->content;
		tmp = tmp->next;
		while (tmp->next != NULL)
		{
			if (i > tmp->content)
				return ("KO");
			i = tmp->content;
			tmp = tmp->next;
		}
		if (i > tmp->content)
			return ("KO");
	}
	else
		return ("KO");
	return ("OK");
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
			return (print_error("Error4\n"));
		free(line);
		print_list(check->a, 'A');
		print_list(check->b, 'B');
	}
	write(1, check_OK_KO(&(check->a)), 2);
	write(1, "\n", 1);
	return (0);
}
