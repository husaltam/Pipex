/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/31 13:04:15 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error("Open infile");
	return (fd);
}

int	open_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit_error("Open outfile");
	return (fd);
}

void	setup_pipe_io(int read_fd, int write_fd)
{
	if (dup2(read_fd, STDIN_FILENO) < 0)
		exit_error("dup2 read");
	if (dup2(write_fd, STDOUT_FILENO) < 0)
		exit_error("dup2 write");
}

void	run_child(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open_infile(argv[1]);
	setup_pipe_io(filein, fd[1]);
	close(filein);
	close(fd[0]);
	exec_command(argv[2], envp);
}

void	run_parent(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open_outfile(argv[4]);
	setup_pipe_io(fd[0], fileout);
	close(fileout);
	close(fd[1]);
	exec_command(argv[3], envp);
}
