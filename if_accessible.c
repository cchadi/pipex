/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_accessible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:05:43 by csaidi            #+#    #+#             */
/*   Updated: 2024/05/05 15:22:02 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **env)
{
	int		i;
	char	*path_oneline;
	char	**split_path;

	path_oneline = NULL;
	split_path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 4) == 0)
		{
			path_oneline = ft_substr(env[i], 5, ft_strlen(env[i]));
			break ;
		}
		else
			i++;
	}
	if (!path_oneline)
		return (NULL);
	split_path = ft_split(path_oneline, ':');
	free(path_oneline);
	return (split_path);
}

char	*accessible(char *path, char *cmd)
{
	char	*partiel;
	char	*full_path;

	if (ft_strchr(cmd, '/') == NULL)
	{
		partiel = ft_strjoin(ft_strdup("/"), cmd);
		full_path = ft_strjoin(path, partiel);
		if (access(full_path, F_OK | X_OK) != -1)
		{
			free(partiel);
			return (full_path);
		}
		else
		{
			free(partiel);
			free(full_path);
			return (NULL);
		}
	}
	else
	{
		if (access(cmd, F_OK | X_OK) == -1)
			ft_printf("%s: No such file or directory\n", cmd);
		return (cmd);
	}
}

char	*if_accessible(char *cmd, char **env)
{
	char	**splited_path;
	char	*command_path;
	int		l;

	splited_path = split_path(env);
	if (!splited_path)
	{
		if (access(cmd, F_OK | X_OK) == -1)
			ft_printf("%s: No such file or directory\n", cmd);
		return (cmd);
	}
	l = 0;
	while (splited_path[l])
	{
		command_path = accessible(ft_strdup(splited_path[l]), cmd);
		if (command_path != NULL)
		{
			ft_free(splited_path);
			return (command_path);
		}
		l++;
	}
	ft_free(splited_path);
	return (NULL);
}
