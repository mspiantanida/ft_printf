/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 07:33:26 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/19 18:08:16 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format_str(char *s, t_flags flags)
{
	int	len;
	int	padding;
	int	count;
	
	count = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (flags.precision >= 0 && flags.precision < len)
		len = flags.precision;
	padding = flags.width - len;
	if (!flags.minus && padding > 0)
		count += ft_putnchar(' ', padding);
	count += write(1, s, len);
	if ( flags.minus && padding > 0)
		count += ft_putnchar(' ', padding);
	return (count);
}
