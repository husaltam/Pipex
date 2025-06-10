/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:10:55 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/30 21:25:52 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

/* pipex functions */
void	run_parent(char **argv, char **envp, int *fd);
void	run_child(char **argv, char **envp, int *fd);
void	setup_pipe_io(int read_fd, int write_fd);
int		open_outfile(char *file);
int		open_infile(char *file);

/* utlis */
void	exec_command(char *arg, char **envp);
char	*get_path(char *cmd, char **envp);
void	exit_error(const char *msg);

#endif
