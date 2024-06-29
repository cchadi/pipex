/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:06:46 by csaidi            #+#    #+#             */
/*   Updated: 2024/05/01 14:49:21 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_var
{
	char	**cmd_1;
	char	**cmd_2;
	char	*cmd_path_1;
	char	*cmd_path_2;
}			t_var;

int			main(int ac, char **av, char **env);
char		*if_accessible(char *cmd, char **env);
void		ft_pipe(char **av, char **env, t_var *var);
char		**command_tableau(char *str);
void		ft_free(char **ptr);

/*--------------------------------------------------*/

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
char		*ft_strchr(char *s, int c);
char		*ft_strtrim(char *s1, char *set);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		**ft_split(char *s, char c);
int			ft_strncmp(char *s1, char *s2, size_t n);

/*---------------------------------------------------*/

int			ft_printf(const char *str, ...);
int			ft_check(char s, va_list args, int len);
int			ft_putchar(char c, int len);
int			ft_putstr(char *s, int len);
int			ft_putnbr(int c, int len);
int			ft_put_positive(unsigned int c, int len);
int			ft_decimal_to_hex(unsigned long decimal, int len);
int			ft_decimal_to_hexa(unsigned int decimal, int len);
int			ft_put_adress(unsigned long decimal, int len);

#endif
