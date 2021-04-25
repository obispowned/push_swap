/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:12:12 by agutierr          #+#    #+#             */
/*   Updated: 2021/04/25 20:25:25 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	int				num;

	num = 0;
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (num == 0))
	{
		num += (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (num == 0)
	{
		num = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (num);
}
