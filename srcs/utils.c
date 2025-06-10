/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husaltam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:39:05 by husaltam          #+#    #+#             */
/*   Updated: 2025/05/31 13:04:20 by husaltam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

static char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	exit_error("PATH not found");
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*temp;
	int		i;

	i = -1;
	paths = ft_split(get_env_path(envp), ':');
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_path, X_OK) == 0)
			return (ft_free_split(paths), full_path);
		free(full_path);
	}
	return (ft_free_split(paths), NULL);
}

void	exec_command(char *arg, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(arg, ' ');
	if (!cmd || !cmd[0])
	{
		ft_free_split(cmd);
		exit_error("Invalid command");
	}
	path = get_path(cmd[0], envp);
	if (!path)
	{
		ft_free_split(cmd);
		exit_error("Command not found");
	}
	execve(path, cmd, envp);
	exit_error("Execve failed");
}
