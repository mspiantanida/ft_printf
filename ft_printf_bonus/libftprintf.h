/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:46:05 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/25 09:11:56 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		precision;
	int		hashtag;
	int		plus;
	int		space;
	int		width;
	char	specifier;
}	t_flags;

size_t	ft_strlen(const char *s);
t_flags	ft_init_flags(void);
t_flags	ft_handle_flags(const char **text);

void	ft_check_flags(const char **text, t_flags *flags);
void	ft_check_width_precision(const char **text, t_flags *flags);

int		ft_format_char(char c, t_flags flags);
int		ft_format_str(char *s, t_flags flags);
int		ft_format_nbr(int n, t_flags flags);
int		ft_convert_nbr(int n, char *buffer);
int		ft_format_sign(char *str, t_flags flags);
int		ft_format_min_int(int n, t_flags flags);
int		ft_format_nbr_flags(int n, int len, t_flags flags, int padding);
int		ft_format_unsigned(unsigned int n, t_flags flags);
int		ft_convert_unsigned(unsigned int n, char *buffer);
int		ft_format_unsigned_flags(char *buffer, int len, t_flags flags);
int		ft_format_ptr(unsigned long ptr, t_flags flags);
int		ft_convert_ptr(unsigned long ptr, char *base, char *buffer);
int		ft_format_hexa(unsigned int nbr, char *base, t_flags flags);
int		ft_convert_hexa(unsigned int n, char *base, char *buffer);
int		ft_format_hexa_flags(char *buffer, int len, t_flags flags);
int		ft_process_format(char c, va_list arguments, t_flags flags);
int		ft_printf(const char *text, ...);
int		ft_putnchar(char c, int n);
int		ft_putstr(char *s);

#endif
