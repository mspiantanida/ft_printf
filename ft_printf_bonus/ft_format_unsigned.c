/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:51:41 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/24 17:48:05 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convert_unsigned(unsigned int n, char *buffer)
{
	int	len;

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
	return (len);
}

int	ft_format_unsigned_flags(char *buffer, int len, t_flags flags)
{
	int	count;

	count = 0;
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
		count += write(1, &buffer[len], 1);
	if (flags.width > flags.precision && flags.minus)
		count += ft_putnchar(' ', flags.width - count);
	return (count);
}

int	ft_format_unsigned(unsigned int n, t_flags flags)
{
	char	buffer[20];
	int		count;
	int		len;

	count = 0;
	len = ft_convert_unsigned(n, buffer);
	if (flags.precision == 0 && n == 0)
	{
		if (flags.width > 0)
			count += ft_putnchar(' ', flags.width);
		return (count);
	}
	count += ft_format_unsigned_flags(buffer, len, flags);
	return (count);
}
