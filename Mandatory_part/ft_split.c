/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:06:46 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/15 16:47:21 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_word(char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

char	*fill_word(char *s, char sep, int *i)
{
	char	*str;
	int		k;
	int		start;

	k = 0;
	while (s[*i] && s[*i] == sep)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != sep)
		(*i)++;
	str = malloc(sizeof(char) * (*i - start + 1));
	if (!str)
		put_error();
	while (start < *i)
		str[k++] = s[start++];
	str[k] = 0;
	return (str);
}

char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

char	**ft_split(char *s, char sep)
{
	char	**string;
	int		i;
	int		j;
	int		wc;

	if (!s)
		return (NULL);
	wc = count_word(s, sep);
	string = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!string)
		return (NULL);
	i = 0;
	j = 0;
	while (wc > j)
	{
		string[j] = fill_word(s, sep, &i);
		if (!string[j])
			ft_free(string);
		j++;
	}
	string[j] = NULL;
	return (free(s), string);
}
