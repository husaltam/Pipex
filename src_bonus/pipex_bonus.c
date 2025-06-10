/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:04:30 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/31 13:04:33 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	here_doc_input(char *limiter)
{
	int		pipe_fd[2];
	char	*line;
	size_t	lim_len;

	if (pipe(pipe_fd) < 0)
		exit_error("here_doc pipe failed");
	lim_len = ft_strlen(limiter);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, lim_len) == 0
			&& line[lim_len] == '\n' && line[lim_len + 1] == '\0')
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

void	run_pipe_commands(t_pipex *px)
{
	int	i;
	int	pipe_fd[2];

	i = 0;
	while (i < px->num_cmds)
	{
		if (i == px->num_cmds - 1)
			run_command(px->argv[px->cmd_start + i],
				px->prev_fd, px->out_fd, px->envp);
		else
		{
			if (pipe(pipe_fd) < 0)
				exit_error("pipe failed");
			run_command(px->argv[px->cmd_start + i],
				px->prev_fd, pipe_fd[1], px->envp);
			close(pipe_fd[1]);
			if (i > 0 || px->here_doc)
				close(px->prev_fd);
			px->prev_fd = pipe_fd[0];
		}
		i++;
	}
}

void	init_pipex(t_pipex *px, int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		write(2, "Usage: ./pipex_bonus infile cmd1 ... cmdN outfile\n", 50);
		write(2, "or: ./pipex_bonus here_doc LIMITER cmd1 ... outfile\n", 55);
		exit(1);
	}
	px->here_doc = (ft_strcmp(argv[1], "here_doc") == 0);
	if (px->here_doc)
		px->cmd_start = 3;
	else
		px->cmd_start = 2;
	px->num_cmds = argc - px->cmd_start - 1;
	px->in_fd = 0;
	px->out_fd = open_outfile(argv[argc - 1], px->here_doc);
	px->argv = argv;
	px->envp = envp;
	if (px->here_doc)
		px->in_fd = here_doc_input(argv[2]);
	else
		px->in_fd = open_infile(argv[1]);
	px->prev_fd = px->in_fd;
}
