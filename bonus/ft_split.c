/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:02:06 by ihaffout          #+#    #+#             */
/*   Updated: 2024/05/15 17:52:25 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*allocation(char *str, char c, int index)
{
	int		i;
	char	*result;
	int		count;

	i = 0;
	count = ft_count(str, c, index);
	result = malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	if (str[index] == 34 || str[index] == 39)
		index++;
	while (i < count)
	{
		result[i] = str[index];
		i++;
		index++;
	}
	result[i] = '\0';
	return (result);
}

char	**clear_arr(char **result, int j)
{
	while (j)
	{
		j--;
		free(result[j]);
	}
	free(result);
	return (NULL);
}

int	string_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && (str[i] == c))
		i++;
	while (str[i])
	{
		count++;
		if (str[i] == 34 || str[i] == 39)
		{
			i++;
			while (str[i] != 34 && str[i] != 39)
				i++;
		}
		while (str[i] && (str[i] != c))
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

int	next_str(char *s, char c, int i)
{
	while (s[i] && s[i] != c)
	{
		if (s[i] == 34 || s[i] == 39)
		{
			i++;
			while (s[i] != 34 && s[i] != 39 && s[i])
				i++;
			if (s[i] == 34 || s[i] == 39)
				i++;
		}
		else
			i++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (string_count(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = allocation(s, c, i);
			if (!result[j])
				return (clear_arr(result, j));
			i = next_str(s, c, i) - 1;
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
