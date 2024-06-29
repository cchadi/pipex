/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:04:59 by csaidi            #+#    #+#             */
/*   Updated: 2024/04/29 16:05:00 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_decimal_to_hexa(unsigned int decimal, int len)
{
	char	*hexnbr;

	hexnbr = "0123456789ABCDEF";
	if (decimal < 16)
		len = ft_putchar(hexnbr[decimal % 16], len);
	else if (decimal >= 16)
	{
		len = ft_decimal_to_hexa(decimal / 16, len);
		len = ft_putchar(hexnbr[decimal % 16], len);
	}
	return (len);
}
