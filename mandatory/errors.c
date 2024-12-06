/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:42:56 by ihaffout          #+#    #+#             */
/*   Updated: 2024/05/24 22:07:09 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(void)
{
	perror("Error");
	exit(1);
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
