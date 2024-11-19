/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:48:38 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/19 18:07:57 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_char(char c, t_flags flags)
{
	int	count;
	int	padding;

	count = 0;
	if (flags.width > 1)
	{
		padding = flags.width - 1;
		if (flags.minus)
		{
			count += write(1, &c, 1);
			count += ft_putnchar(' ', padding);
		}
		else
		{
			if (flags.zero)
				count += ft_putnchar('0', padding);
			else
				count += ft_putnchar(' ', padding);
			count += write(1, &c, 1);
		}
	}
	else
		count += write(1, &c, 1);
	return (count);
}
