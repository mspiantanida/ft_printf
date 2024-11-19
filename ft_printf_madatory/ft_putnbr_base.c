/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:54:46 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/19 09:31:14 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= (unsigned int)base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += write (1, &base[nbr % base_len], 1);
	return (count);
}

/*int	main(void)
{
	char	base_hexadecimal_up [17] = "0123456789ABCDEF";
	char	base_hexadecimal_low [17] = "0123456789abcdef";
	int	count;

	count = ft_putnbr_base(-2147483648, base_hexadecimal_up);
	write(1, "\n", 1);
	printf("Chars written: %d\n", count);

	count = ft_putnbr_base(0, base_hexadecimal_up);
	write(1, "\n", 1);
        printf("Chars written: %d\n", count);

	count = ft_putnbr_base(2147483647, base_hexadecimal_up);
	write(1, "\n", 1);
        printf("Chars written: %d\n", count);

        count = ft_putnbr_base(42, base_hexadecimal_low);
        write(1, "\n", 1);
        printf("Chars written: %d\n", count);

        count = ft_putnbr_base(-42, base_hexadecimal_low);
        write(1, "\n", 1);
        printf("Chars written: %d\n", count);
	return (0);
}*/
