/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:48:48 by ihaffout          #+#    #+#             */
/*   Updated: 2024/05/24 22:17:58 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*grep_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (check_access(path, paths, i) == 0)
			return (path);
		free(paths[i++]);
		free(path);
	}
	free(paths);
	return (NULL);
}

void	get_input(char *limiter, int *fd_pipe)
{
	int		i;
	char	*str;

	i = 0;
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[0]);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (ft_strcmp(str, limiter) || !str)
			exit(1);
		write(fd_pipe[1], str, ft_strlen(str));
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if ((s1[i] == '\0' || s1[i] == '\n') && (s2[i] == '\0' || s2[i] == '\n'))
		return (1);
	return (0);
}

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

int	check_access(char *path, char **paths, int index)
{
	if (access(path, F_OK) == 0)
	{
		while (paths[index])
			free(paths[index++]);
		free(paths);
		return (0);
	}
	return (1);
}
