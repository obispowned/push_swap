/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:11:31 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/18 17:28:44 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	tell_me_the_positions(t_stack	**stack, long *a)
{
	t_stack	*aux;
	int		i;

	aux = *stack;
	while (aux)
	{
		i = 0;
		while (a[i] != aux->content)
			i++;
		if (a[i] == aux->content)
			aux->position = i + 1;
		aux = aux->next;
	}
}

int	check_stdin2(t_check *check, char *line)
{
	if ((strcmp((const char *)line, "sa") == 0)
		|| (strcmp((const char *)line, "sb") == 0)
		|| (strcmp((const char *)line, "ss") == 0))
		sx(check, line, 'c');
	else if ((strcmp((const char *)line, "ra") == 0)
		|| (strcmp((const char *)line, "rb") == 0)
		|| (strcmp((const char *)line, "rr") == 0))
		rx(check, line, 'c');
	else if ((strcmp((const char *)line, "rra") == 0)
		|| (strcmp((const char *)line, "rrb") == 0)
		|| (strcmp((const char *)line, "rrr") == 0))
		rrx(check, line, 'c');
	else if ((strcmp((const char *)line, "pa") == 0)
		|| (strcmp((const char *)line, "pb") == 0))
		px(check, line, 'c');
	else if (strcmp((const char *)line, "") == 0)
		return (-1);
	else
		return (print_error("Error\n"));
	return (0);
}

int	check_stdin(t_check *check)
{
	int		size;
	char	*line;
	int		ret;

	size = get_next_line(0, &line);
	while (size > 0)
	{
		ret = check_stdin2(check, line);
		if (ret == -1)
			break ;
		else if (ret == 1)
			return (1);
		free(line);
		size = get_next_line(0, &line);
	}
	write(1, check_OK_KO(&(check->a)), 3);
	return (0);
}
