/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:51:07 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/25 08:28:10 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_sign(char *str, t_flags flags)
{
	int	len;
	int	count;

	len = ft_strlen(str);
	count = 0;
	if (flags.plus && *str != '-')
		count += write(1, "+", 1);
	else if (flags.space && *str != '-')
		count += write(1, " ", 1);
	count += write(1, str, len);
	return (count);
}

int	ft_convert_nbr(int n, char *buffer)
{
	int		len;

	len = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
	{
		buffer[0] = '0';
		len++;
	}
	while (n > 0)
	{
		buffer[len++] = (n % 10) + '0';
		n /= 10;
	}
	return (len);
}

int	ft_format_min_int(int n, t_flags flags)
{
	int	count;
	int	len;
	int	padding;
	int	total_width;

	count = 0;
	len = ft_strlen("2147483648");
	padding = 0;
	total_width = 0;
	if (n != -2147483648)
		return (0);
	if (flags.precision > len)
		padding = flags.precision - len;
	total_width = len + padding + 1;
	if (!flags.minus && flags.width > total_width && !flags.zero)
		count += ft_putnchar(' ', flags.width - total_width);
	count += write(1, "-", 1);
	if (flags.zero && flags.width > total_width && !flags.minus)
		count += ft_putnchar('0', flags.width - total_width);
	count += ft_putnchar('0', padding);
	count += write(1, "2147483648", len);
	if (flags.minus && flags.width > total_width)
		count += ft_putnchar(' ', flags.width - total_width);
	return (count);
}

int	ft_format_nbr_flags(int n, int len, t_flags flags, int padding)
{
	int	count;
	int	total_width;

	count = 0;
	total_width = len + padding;
	if (flags.precision >= 0 && flags.zero)
		flags.zero = 0;
	if (n < 0 || flags.plus || flags.space)
		total_width += 1;
	if (!flags.minus && flags.width > total_width && !flags.zero)
		count += ft_putnchar(' ', flags.width - total_width);
	if (n < 0)
		count += write(1, "-", 1);
	else if (flags.plus)
		count += write(1, "+", 1);
	else if (flags.space)
		count += write(1, " ", 1);
	if (flags.zero && flags.width > total_width && !flags.minus)
		count += ft_putnchar('0', flags.width - total_width);
	count += ft_putnchar('0', padding);
	return (count);
}

int	ft_format_nbr(int n, t_flags flags)
{
	char	buffer[20];
	int		len;
	int		padding;
	int		total_width;
	int		count;

	padding = 0;
	count = 0;
	if (n == -2147483648)
		return (ft_format_min_int(n, flags));
	if (n < 0)
		len = ft_convert_nbr(-n, buffer);
	else
		len = ft_convert_nbr(n, buffer);
	if (n == 0 && flags.precision == 0)
		len = 0;
	if (flags.precision > len)
		padding = flags.precision - len;
	count += ft_format_nbr_flags(n, len, flags, padding);
	total_width = len + padding + (n < 0 || flags.plus || flags.space);
	while (--len >= 0)
		count += write(1, &buffer[len], 1);
	if (flags.minus && flags.width > total_width)
		count += ft_putnchar(' ', flags.width - total_width);
	return (count);
}
