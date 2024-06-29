/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:05:20 by csaidi            #+#    #+#             */
/*   Updated: 2024/04/29 16:05:21 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_putstr(char *s, int len)
{
	int	i;

	if (!s)
		return (len = ft_putstr("(null)", len));
	i = 0;
	while (s[i])
	{
		len = ft_putchar(s[i], len);
		i++;
	}
	return (len);
}
