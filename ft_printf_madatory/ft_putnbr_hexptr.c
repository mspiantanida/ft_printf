/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:54:46 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/19 08:24:01 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_hexptr(unsigned long nbr, char *base)
{
	unsigned long	base_len;
	int				count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr >= base_len)
		count += ft_putnbr_hexptr(nbr / base_len, base);
	count += write (1, &base[nbr % base_len], 1);
	return (count);
}
