/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:00:14 by ihaffout          #+#    #+#             */
/*   Updated: 2024/05/24 22:23:24 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_case(int *fd, int *index, int ac, char **av)
{
	int		fd_pipe[2];
	pid_t	id;

	fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd[1] == -1)
		ft_exit();
	if (ac < 6)
		ft_error("Error: you must add more parameters");
	if (pipe(fd_pipe) == -1)
		ft_exit();
	id = fork();
	if (id == -1)
		ft_exit();
	if (id == 0)
		get_input(av[2], fd_pipe);
	else
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], STDIN_FILENO);
		close(fd_pipe[0]);
		waitpid(id, NULL, 0);
	}
	*index = 3;
}

void	second_case(int *fd, int *index, int ac, char **av)
{
	fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		ft_exit();
	if (ac < 5)
		ft_error("Error: you must add more parameters");
	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
		ft_exit();
	dup2(fd[0], STDIN_FILENO);
	*index = 2;
}

void	multiple_pipes(char *cmd, char **envp, int *cmds_nbr)
{
	int		pipe_fd[2];
	pid_t	id;

	if (pipe(pipe_fd) == -1)
		ft_exit();
	id = fork();
	if (id == -1)
		ft_exit();
	if (id == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		execute(cmd, envp);
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	*cmds_nbr += 1;
}

void	execute(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**cmds;
	char	*command;

	cmds = ft_split(cmd, ' ');
	command = ft_strjoin("/", cmds[0]);
	if (!cmds || !command)
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

int	main(int ac, char **av, char **envp)
{
	int		i;
	pid_t	id;
	int		fd[2];
	int		cmds_nbr;

	if (ft_strcmp("here_doc", av[1]))
		first_case(fd, &i, ac, av);
	else
		second_case(fd, &i, ac, av);
	while (i < ac - 2)
		multiple_pipes(av[i++], envp, &cmds_nbr);
	id = fork();
	if (id == -1)
		ft_exit();
	if (id == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		execute(av[ac - 2], envp);
	}
	while (cmds_nbr-- >= 0)
		wait(NULL);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
