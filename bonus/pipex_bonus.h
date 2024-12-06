/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:01:03 by ihaffout          #+#    #+#             */
/*   Updated: 2024/05/24 22:25:42 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*-------------------------------- PIPEX --------------------------------*/
void	first_case(int *fd, int *index, int ac, char **av);
void	second_case(int *fd, int *index, int ac, char **av);
void	multiple_pipes(char *cmd, char **envp, int *cmds_nbr);
void	execute(char *cmd, char **envp);

/*-------------------------------- UTILS --------------------------------*/

int		ft_strcmp(char *s1, char *s2);
int		ft_count(char *str, char c, int index);
int		check_access(char *path, char **paths, int index);
char	*ft_free(char *buffer);
char	*ft_strchr(const char *s, int c);
char	*grep_path(char *cmd, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	get_input(char *limiter, int *fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char const *s);

//--------- errors ---------//
void	ft_exit(void);
void	ft_error(char *str);

//--------- ft_split ---------//
int		next_str(char *s, char c, int i);
int		string_count(char *str, char c);
char	*allocation(char *str, char c, int index);
char	**ft_split(char *s, char c);
char	**clear_arr(char **result, int j);

//--------- get_next_line ---------//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_string(int fd, char *str);
char	*ft_before_the_new_line(char *str);
char	*ft_after_the_new_line(char *str);

#endif