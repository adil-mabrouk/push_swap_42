/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:39:48 by amabrouk          #+#    #+#             */
/*   Updated: 2024/02/16 10:21:59 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (s[++i])
		copy[i] = s[i];
	copy[i] = 0;
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		len;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (free(s1), s1 = NULL, ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
		put_error();
	i = -1;
	while (++i < ft_strlen(s1))
		string[i] = s1[i];
	j = 0;
	string[i++] = ' ';
	while (i < len)
		string[i++] = s2[j++];
	string[i] = 0;
	return (free(s1), s1 = NULL, string);
}
