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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <wordexp.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		prev_fd;
	int		here_doc;
	int		cmd_start;
	int		num_cmds;
	char	**argv;
	char	**envp;
}	t_pipex;

/* pipex functions*/
void	run_pipe_commands(t_pipex *px);
void	init_pipex(t_pipex *px, int argc, char **argv, char **envp);

/* utils */
int		open_infile(char *filename);
int		here_doc_input(char *limiter);
int		open_outfile(char *filename, int here_doc);
void	exit_error(char *msg);
void	exec_command(char *cmd, char **envp);
void	run_command(char *cmd, int in_fd, int out_fd, char **envp);

#endif
