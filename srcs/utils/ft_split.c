/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:20:25 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/15 17:30:35 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static size_t	count_segment(char const *s, char c)
{
	size_t		counter;
	int			i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*clone;
	size_t	i;

	clone = (char *)malloc(sizeof(char) * (n + 1));
	if (!clone)
		return (NULL);
	i = 0;
	while (i < n)
	{
		clone[i] = s1[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}

static void	*destroy_strs(char **strs)
{
	int		i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	tab_counter;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	tab_counter = count_segment(s, c);
	strs = (char **)malloc(sizeof(char *) * (tab_counter + 1));
	if (!strs)
		return (NULL);
	tab_counter = 0;
	j = -1;
	while (s[++j])
	{
		if (s[j] == c)
			continue ;
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		if ((strs[tab_counter++] = ft_strndup(&s[j], i)) == NULL)
			return (destroy_strs(strs));
		j += i - 1;
	}
	strs[tab_counter] = NULL;
	return (strs);
}
