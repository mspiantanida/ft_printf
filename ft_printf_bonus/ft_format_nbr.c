/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:51:07 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/18 18:16:37 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_sign(char *str, t_flags flags)
{
	int	len;
	int	count;

	len = ft_strlen(str);
	count = 0;
	if (flags.width > len && !flags.minus)
		count += ft_putnchar(' ', flags.width - len);
	count += ft_putstr(str);
	if (flags.width > len && flags.minus)
		count += ft_putnchar(' ', flags.width - len);
	return (count);
}

int	ft_format_nbr(int n, t_flags flags)
{
	char	buffer[12];
	int	len;
	int	count;
	int	n_negative;

	len = 0;
	count = 0;
	n_negative = (n < 0);
	if (n == -2147483648)
		return (ft_format_sign("-2147483648", flags));
	if (n_negative)
		n = -n;
	while (n > 0 || len == 0)
	{
		buffer[len++] = (n % 10) + '0';
		n /= 10;
	}
	if (n_negative || flags.plus || flags.space)
		flags.width--;
	if (flags.precision > len)
		count += ft_putnchar('0', flags.precision - len);
	if (n_negative)
		count += write (1, "-", 1);
	else if (flags.plus)
		count += write (1, "+", 1);
	else if (flags.space)
		count += write (1, " ", 1);
	if (flags.width > len + count && !flags.minus && !flags.zero)
		count += ft_putnchar(' ', flags.width - (len + count));
	while (len > 0)
		count += write(1, &buffer[len--], 1);
	if (flags.width > len + count && flags.minus)
		count += ft_putnchar(' ', flags.width - count);
	return (count);
}
