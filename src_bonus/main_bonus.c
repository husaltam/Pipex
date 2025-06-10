/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 22:39:27 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/31 13:04:27 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	init_pipex(&px, argc, argv, envp);
	run_pipe_commands(&px);
	close(px.in_fd);
	close(px.out_fd);
	while (wait(NULL) > 0)
		;
	return (0);
}
