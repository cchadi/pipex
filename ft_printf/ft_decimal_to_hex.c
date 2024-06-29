/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:04:52 by csaidi            #+#    #+#             */
/*   Updated: 2024/04/29 16:04:54 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_decimal_to_hex(unsigned long decimal, int len)
{
	char	*hexnbr;

	hexnbr = "0123456789abcdef";
	if (decimal < 16)
		len = ft_putchar(hexnbr[decimal % 16], len);
	else if (decimal >= 16)
	{
		len = ft_decimal_to_hex(decimal / 16, len);
		len = ft_putchar(hexnbr[decimal % 16], len);
	}
	return (len);
}
