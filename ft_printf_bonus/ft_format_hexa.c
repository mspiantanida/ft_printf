/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:54:46 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/25 14:50:18 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convert_hexa(unsigned int n, char *base, char *buffer)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n == 0)
		buffer[len++] = base[0];
	while (n > 0)
	{
		buffer[len++] = base[n % base_len];
		n /= base_len;
	}
	return (len);
}

int	ft_format_hexa_flags(char *buffer, int len, t_flags flags)
{
	int	count;
	int	padding;

	count = 0;
	padding = 0;
	if (flags.precision > len)
		count += ft_putnchar('0', flags.precision - len);
	if (flags.width > len && !flags.minus)
	{
		padding = flags.width - len;
		if (flags.zero && flags.precision <= len)
			count += ft_putnchar('0', padding);
		else
			count += ft_putnchar(' ', padding);
	}
	while (--len >= 0)
		count += write(1, &buffer[len], 1);
	if (flags.width > flags.precision && flags.minus)
		count += ft_putnchar(' ', flags.width - count);
	return (count);
}

int	ft_format_hexa(unsigned int n, char *base, t_flags flags)
{
	char	buffer[20];
	int		count;
	int		len;

	count = 0;
	len = ft_convert_hexa(n, base, buffer);
	if (n == 0 && flags.precision == 0)
		len = 0;
	if (flags.hashtag && n != 0)
	{
		if (flags.specifier == 'X')
			count += write(1, "0X", 2);
		else if (flags.specifier == 'x')
			count += write(1, "0x", 2);
	}
	count += ft_format_hexa_flags(buffer, len, flags);
	return (count);
}
