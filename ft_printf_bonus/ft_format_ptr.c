/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:18:10 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/24 13:50:24 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convert_ptr(unsigned long ptr, char *base, char *buffer)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (ptr == 0)
		buffer[len++] = base[0];
	while (ptr > 0)
	{
		buffer[len++] = base[ptr % base_len];
		ptr /= base_len;
	}
	return (len);
}

int	ft_format_ptr(unsigned long ptr, t_flags flags)
{
	char	buffer[20];
	int		hexa_len;
	int		total_len;
	int		padding;
	int		count;

	count = 0;
	if (!ptr)
		return (ft_format_str("(nil)", flags));
	hexa_len = ft_convert_ptr(ptr, "0123456789abcdef", buffer) + 2;
	total_len = hexa_len;
	if (flags.width > total_len)
		padding = flags.width - total_len;
	else
		padding = 0;
	if (!flags.minus)
		count += ft_putnchar(' ', padding);
	count += write(1, "0x", 2);
	while (--hexa_len > 1)
		count += write(1, &buffer[hexa_len - 2], 1);
	if (flags.minus)
		count += ft_putnchar(' ', padding);
	return (count);
}
