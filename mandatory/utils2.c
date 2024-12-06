/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:05:00 by ihaffout          #+#    #+#             */
/*   Updated: 2024/05/15 21:43:25 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return (((char *)haystack) + i);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;
	size_t	result_len;

	i = 0;
	j = 0;
	result_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * (result_len));
	if (!result)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			result[i++] = s1[j++];
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			result[i++] = s2[j++];
	}
	result[i] = '\0';
	return (result);
}

int	ft_count(char *str, char c, int index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	i = index;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			i++;
			while (str[i] != 39 && str[i] != 34)
			{
				count++;
				i++;
			}
			return (count);
		}
		if (str[i] == c)
			break ;
		count++;
		i++;
	}
	return (count);
}
