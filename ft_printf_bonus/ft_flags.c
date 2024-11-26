/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:33:52 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/24 12:42:51 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags = (t_flags){0, 0, -1, 0, 0, 0, 0, 0};
	return (flags);
}

void	ft_check_flags(const char **text, t_flags *flags)
{
	while (**text == '-' || **text == '0' || **text == '#' || **text == '+'
		|| **text == ' ')
	{
		if (**text == '-')
			flags->minus = 1;
		else if (**text == '0')
			flags->zero = 1;
		else if (**text == '#')
			flags->hashtag = 1;
		else if (**text == '+')
			flags->plus = 1;
		else if (**text == ' ')
			flags->space = 1;
		(*text)++;
	}
	if (flags->plus && flags->space)
	{
		flags->space = 0;
	}
}

void	ft_check_width_precision(const char **text, t_flags *flags)
{
	while (**text >= '0' && **text <= '9')
	{
		flags->width = flags->width * 10 + (**text - '0');
		(*text)++;
	}
	if (**text == '.')
	{
		flags->precision = 0;
		(*text)++;
		while (**text >= '0' && **text <= '9')
		{
			flags->precision = flags->precision * 10 + (**text - '0');
			(*text)++;
		}
	}
}

t_flags	ft_handle_flags(const char **text)
{
	t_flags	flags;

	flags = ft_init_flags();
	ft_check_flags(text, &flags);
	ft_check_width_precision(text, &flags);
	flags.specifier = **text;
	return (flags);
}
