/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:14:14 by ihaffout          #+#    #+#             */
/*   Updated: 2024/05/24 22:09:47 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	execute(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**cmds;
	char	*command;

	cmds = ft_split(cmd, ' ');
	if (!cmds)
		ft_exit();
	command = ft_strjoin("/", cmds[0]);
	if (!command)
		ft_exit();
	path = grep_path(command, envp);
	if (!path)
	{
		i = 0;
		while (cmds[i])
			free(cmds[i++]);
		free(cmds);
		free(command);
		ft_exit();
	}
	free(command);
	if (execve(path, cmds, envp) == -1)
		ft_exit();
}

void	child_process_1(char *file1, char *cmd1, int *fd, char **envp)
{
	int	file1_fd;

	file1_fd = open(file1, O_RDONLY);
	if (file1_fd == -1)
		ft_exit();
	dup2(file1_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(cmd1, envp);
}

void	child_process_2(char *file2, char *cmd2, int *fd, char **envp)
{
	int	file2_fd;

	file2_fd = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file2_fd == -1)
		ft_exit();
	dup2(file2_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execute(cmd2, envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	id1;
	pid_t	id2;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			ft_exit();
		id1 = fork();
		if (id1 == -1)
			ft_exit();
		if (id1 == 0)
			child_process_1(av[1], av[2], fd, envp);
		id2 = fork();
		if (id2 == -1)
			ft_exit();
		if (id2 == 0)
			child_process_2(av[4], av[3], fd, envp);
		close(fd[1]);
		close(fd[0]);
		wait(NULL);
		wait(NULL);
	}
	return (0);
}
