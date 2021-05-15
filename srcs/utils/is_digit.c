/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:43:37 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/15 17:39:23 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	isallnum(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] > '9' || file[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int	isallnum_and_spa(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if ((file[i] > '9' || file[i] < '0') && (file[i] != ' '))
			return (1);
		i++;
	}
	return (0);
}

int	isallnum_and_minus(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if ((file[i] > '9' || file[i] < '0') && (file[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}

int	isallnum_and_spa_and_minus(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if ((file[i] > '9' || file[i] < '0')
			&& (file[i] != ' ') && (file[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}

int	is_spa(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}
