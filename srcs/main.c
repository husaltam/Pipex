/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/31 13:04:11 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	setup_and_validate(int argc, char **argv, int *fd)
{
	int	fd_out;

	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 41);
		exit(EXIT_FAILURE);
	}
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
		exit_error("Open outfile");
	close(fd_out);
	if (pipe(fd) < 0)
		exit_error("Pipe error");
}

/** Handles forking and execution of both child and parent processes */
void	handle_forking(char **argv, char **envp, int *fd)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		exit_error("Fork error");
	if (pid1 == 0)
		run_child(argv, envp, fd);
	pid2 = fork();
	if (pid2 < 0)
		exit_error("Fork error");
	if (pid2 == 0)
		run_parent(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

/** Main function */
int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	setup_and_validate(argc, argv, fd);
	handle_forking(argv, envp, fd);
	return (0);
}
