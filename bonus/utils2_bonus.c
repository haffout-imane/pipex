/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:02:38 by ihaffout          #+#    #+#             */
/*   Updated: 2024/05/15 18:18:15 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s);
		i++;
	}
	return (NULL);
}

char	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
