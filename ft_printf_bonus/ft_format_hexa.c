/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:54:46 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/19 18:57:30 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_hexa(unsigned int n, char *base, t_flags flags)
{
	char	buffer[20];
	int	count;
	int	len;
	int	base_len;

	count = 0;
	len = 0;
	base_len = ft_strlen(base);
	if (n == 0)
		buffer[len++] = base[0];
	while (n > 0)
	{
		buffer[len++] = base[n % base_len];
		n /= base_len;
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
