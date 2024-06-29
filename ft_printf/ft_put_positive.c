/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_positive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:05:09 by csaidi            #+#    #+#             */
/*   Updated: 2024/04/29 16:05:10 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_put_positive(unsigned int c, int len)
{
	if (c >= 10)
	{
		len = ft_putnbr(c / 10, len);
		len = ft_putchar(c % 10 + 48, len);
	}
	else if (c >= 0 && c < 10)
		len = ft_putchar(c + 48, len);
	return (len);
}
