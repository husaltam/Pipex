/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:39:54 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/31 13:04:39 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("!\n", 2);
	exit(1);
}

void	exec_command(char *cmd, char **envp)
{
	char	*argv[4];

	argv[0] = "sh";
	argv[1] = "-c";
	argv[2] = cmd;
	argv[3] = NULL;
	execve("/bin/sh", argv, envp);
	exit_error("execve failed");
}

int	open_outfile(char *filename, int here_doc)
{
	int	fd;

	if (here_doc)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit_error("outfile open failed");
	return (fd);
}

int	open_infile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("infile open failed");
	return (fd);
}

void	run_command(char *cmd, int in_fd, int out_fd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_error("fork failed");
	if (pid == 0)
	{
		if (dup2(in_fd, STDIN_FILENO) < 0)
			exit_error("dup2 input");
		if (dup2(out_fd, STDOUT_FILENO) < 0)
			exit_error("dup2 output");
		exec_command(cmd, envp);
	}
}
