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

int	ft_putnbr(int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += write (1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	digit = (n % 10) + '0';
	count += write (1, &digit, 1);
	return (count);
}

/*int	main()
{
	int	num;

	num = -2147483648;
	ft_putnbr(num);
	write (1, "\n", 1);

	num = 42;
	ft_putnbr(num);
	write (1, "\n", 1);

	num = -42;
	ft_putnbr(num);
	write (1, "\n", 1);

	num = 0;
	ft_putnbr(num);
	write (1, "\n", 1);
}*/
