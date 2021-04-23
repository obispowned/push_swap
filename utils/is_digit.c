/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:43:37 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/14 11:43:46 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int			isallnum(char *file)
{ //solo digitos ret 0, error ret 1
	int		i;

	i = 0;
	while (file[i])
	{
		if (file[i] > '9' || file[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int			isallnum_and_spa(char *file)
{ // solo digitos ret 0, error ret 1
	int		i;

	i = 0;
	while (file[i])
	{
		if ((file[i] > '9' || file[i] < '0') && (file[i] != ' '))
			return (1);
		i++;
	}
	return (0);
}

int			isallnum_and_minus(char *file)
{ // solo digitos ret 0, error ret 1
	int		i;

	i = 0;
	while (file[i])
	{
		if ((file[i] > '9' || file[i] < '0') && (file[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}

int			isallnum_and_spa_and_minus(char *file)
{ // solo digitos ret 0, error ret 1
	int		i;

	i = 0;
	while (file[i])
	{
		if ((file[i] > '9' || file[i] < '0') && (file[i] != ' ') && (file[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}

int			is_spa(char *file)
{ // si hay algun espacio en la cadena ret 0, si no hay espacios: ret 1
	int		i;

	i = 0;
	while (file[i])
	{
		if (file[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}