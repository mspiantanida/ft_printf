/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:51:41 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/19 18:29:59 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_unsigned(unsigned int n, t_flags flags)
{
	char	buffer[20];
	int	count;
	int	len;

	count = 0;
	len = 0;
	if (n == 0)
		buffer[len++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[len++] = (n % 10) + '0';
			n /= 10; 
		}
	}
	if (flags.precision > len)
		count += ft_putnchar('0', flags.precision - len);
	if (flags.width > flags.precision && !flags.minus)
	{
		if (flags.zero)
			count += ft_putnchar('0', flags.width - len);
		else
			count += ft_putnchar(' ', flags.width - len);
	}
	while (--len >= 0)
		count += write(1, &buffer[len],1);
	if (flags.width > flags.precision && flags.minus)
		count += ft_putnchar(' ', flags.width - count);
	return (count);
}
