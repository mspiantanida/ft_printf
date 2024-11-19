/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:46:05 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/19 15:46:05 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

typedef	struct	s_flags
{
	int	minus;
	int	zero;
	int	precision;
	int	hashtag;
	int	plus;
	int	space;
	int	width;
	char	specifier;
}	t_flags;

size_t	ft_strlen(const char *s);
t_flags ft_check_flags(const char **text);
int		ft_format_char(char c, t_flags flags);
int		ft_format_str(char *s, t_flags flags);
int		ft_format_nbr(int n, t_flags flags);
int		ft_format_unsigned(unsigned int n, t_flags flags);
int		ft_format_ptr(unsigned long ptr, t_flags flags);
int		ft_format_hexa(unsigned int nbr, char *base, t_flags flags);
int		ft_putnchar(char c, int n);
int		ft_putstr(char *s);
int		ft_printf(const char *text, ...);

#endif
