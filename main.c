/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:05:47 by csaidi            #+#    #+#             */
/*   Updated: 2024/05/05 15:26:11 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_cmd(char **av, char **env, t_var *t)
{
	t->cmd_1 = command_tableau(av[2]);
	t->cmd_2 = command_tableau(av[3]);
	if (t->cmd_1[0] != NULL)
		t->cmd_path_1 = if_accessible(t->cmd_1[0], env);
	if (t->cmd_2[0] != NULL)
		t->cmd_path_2 = if_accessible(t->cmd_2[0], env);
	if (!(t->cmd_path_1) || t->cmd_1[0] == NULL)
		ft_printf("%s: command not found\n", t->cmd_1[0]);
	if (!(t->cmd_path_2) || t->cmd_2[0] == NULL)
		ft_printf("%s: command not found\n", t->cmd_2[0]);
}

void	ft_free(char **ptr)
{
	int	l;

	l = 0;
	while (ptr[l])
	{
		free(ptr[l]);
		l++;
	}
	free(ptr);
}

int	main(int ac, char **av, char **env)
{
	t_var	v;

	if (ac == 5)
	{
		check_cmd(av, env, &v);
		ft_pipe(av, env, &v);
	}
	else
	{
		ft_printf("the number of argument is not valid\n");
		return (0);
	}
}
