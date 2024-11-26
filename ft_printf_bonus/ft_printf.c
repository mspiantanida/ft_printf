/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:35:02 by mpiantan          #+#    #+#             */
/*   Updated: 2024/11/25 15:17:31 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_process_format(char c, va_list arguments, t_flags flags)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_format_char(va_arg(arguments, int), flags);
	else if (c == 's')
		count += ft_format_str(va_arg(arguments, char *), flags);
	else if (c == 'i' || c == 'd')
		count += ft_format_nbr(va_arg(arguments, int), flags);
	else if (c == 'u')
		count += ft_format_unsigned(va_arg(arguments, unsigned int), flags);
	else if (c == 'p')
		count += ft_format_ptr(va_arg(arguments, unsigned long), flags);
	else if (c == 'x')
		count += ft_format_hexa(va_arg(arguments, unsigned long),
				"0123456789abcdef", flags);
	else if (c == 'X')
		count += ft_format_hexa(va_arg(arguments, unsigned long),
				"0123456789ABCDEF", flags);
	else if (c == '%')
		count += ft_format_char('%', flags);
	return (count);
}

int	ft_printf(const char *text, ...)
{
	va_list	arguments;
	t_flags	flags;
	int		count;

	count = 0;
	va_start(arguments, text);
	while (*text)
	{
		if (*text == '%' && *(text + 1))
		{
			text++;
			flags = ft_handle_flags(&text);
			count += ft_process_format(flags.specifier, arguments, flags);
		}
		else
			count += write (1, text, 1);
		text++;
	}
	va_end(arguments);
	return (count);
}

/*#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	count1;
	int	count2;
	
	//Basic tests
	count1 = ft_printf("Basic string: Hello, World!\n");
	count2 = printf("Basic string: Hello, World!\n");
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Percent sign: %%\n");
	count2 = printf("Percent sign: %%\n");
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Characters: %c %c %c\n", 'A', 'B', 'C');
	count2 = printf("Characters: %c %c %c\n", 'A', 'B', 'C');
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("String: %s\n", "42 is awesome!");
	count2 = printf("String: %s\n", "42 is awesome!"); 
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Integer: %d\n", 42);
	count2 = printf("Integer: %d\n", 42);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Negative integer: %i\n", -42);
	count2 = printf("Negative integer: %i\n", -42);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Unsigned integer: %u\n", 4294967295U);
	count2 = printf("Unsigned integer: %u\n", 4294967295U);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Hexadecimal lowercase: %x\n", 255);
	count2 = printf("Hexadecimal lowercase: %x\n", 255);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Hexadecimal uppercase: %X\n", 255);
	count2 = printf("Hexadecimal uppercase: %X\n", 255);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Pointer: %p\n", (void *)0x12345678);
	count2 = printf("Pointer: %p\n", (void *)0x12345678);
	printf("%d = %d\n", count1, count2);

	// Edge cases for int
	count1 = ft_printf("Minimun int value: %d\n", INT_MIN);
	count2 = printf("Minimun int value: %d\n", INT_MIN);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Maximun int value: %d\n", INT_MAX);
	count2 = printf("Maximun int value: %d\n", INT_MAX);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Negative edge case (min signed int): %d\n", -2147483647);
	count2 = printf("Negative edge case (min signed int): %d\n", -2147483647);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Positive edge case (max signed int): %d\n", 2147483647);
	count2 = printf("Positive edge case (max signed int): %d\n", 2147483647);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Unsigned edge case (max unsigned int): %u\n",
				4294967295U);
	count2 = printf("Unsigned edge case (max unsigned int): %u\n", 4294967295U);
	printf("%d = %d\n", count1, count2);

	// Edge cases for strings: Long strings
	char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. ";
	count1 = ft_printf("%s\n", long_str);
	count2 = printf("%s\n", long_str);
	printf("%d = %d\n", count1, count2);

	char *long_string = "This is a very long string that exceeds normal"
	"usage limits to see how ft_printf handles large input without truncation.";
	count1 = ft_printf("%s\n", long_string);
	count2 = printf("%s\n", long_string);
	printf("%d = %d\n", count1, count2);

	// Edge cases for hexadecimal
	count1 = ft_printf("Hex 0x0: %x\n", 0);
        count2 = printf("Hex 0x0: %x\n", 0);
        printf("%d = %d\n", count1, count2);

        count1 = ft_printf("Hex UINT_MAX: %x\n", UINT_MAX);
        count2 = printf("Hex UINT_MAX: %x\n", UINT_MAX);
        printf("%d = %d\n", count1, count2);

	// Edge cases for pointers and nulls
        count1 = ft_printf("Pointer with actual address: %p\n", &main);
        count2 = printf("Pointer with actual address: %p\n", &main);
        printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Null pointer: %p\n", NULL);
	count2 = printf("Null pointer: %p\n", NULL);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Empty string: %s\n", "");
	count2 = printf("Empty string: %s\n", "");
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Null string: %s\n", (char *)NULL);
	count2 = printf("Null string: %s\n", (char *)NULL);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Null pointer: %p\n", NULL);
	count2 = printf("Null pointer: %p\n", NULL);
	printf("%d = %d\n", count1, count2);

	int x = 42;
	count1 = ft_printf("Int pointer: %p\n", &x);
	count2 = printf("Int pointer: %p\n", &x);
	printf("%d = %d\n", count1, count2);

	char str[] = "Test";
	count1 = ft_printf("Array pointer: %p\n", str);
	count2 = printf("Array pointer: %p\n", str);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Zero integer: %d\n", 0);
	count2 = printf("Zero integer: %d\n", 0);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Zero unsigned: %u\n", 0);
	count2 = printf("Zero unsigned: %u\n", 0);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Zero pointer: %p\n", (void *)0);
	count2 = printf("Zero pointer: %p\n", (void *)0);
	printf("%d = %d\n", count1, count2);

	// Complex formatting with multiple types
	count1 = ft_printf("Multiple types: %u, %d, %x, %X, %%\n",
				UINT_MAX, INT_MIN, 0x7FFF, 0xFFF);
	count2 = printf("Multiple types: %u, %d, %x, %X, %%\n",
                                UINT_MAX, INT_MIN, 0x7FFF, 0xFFF);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Mix: %d %s %c %x %p %%\n",
			123, "Test", 'A', 255, &x);
	count2 = printf("Mix: %d %s %c %x %p %%\n",
			123, "Test", 'A', 255, &x);
	printf("%d = %d\n", count1, count2);
	
	// Special characters
	count1 = ft_printf("Null character: %c\n", '\0');
	count2 = printf("Null character: %c\n", '\0');
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("String with new line: %s\n",
				"This is a string with a newline\n");
	count2 = printf("String with new line: %s\n",
                                "This is a string with a newline\n");
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Special chars: %s\n", "\tTab\nNewline");
	count2 = printf("Special chars: %s\n", "\tTab\nNewline");
	printf("%d = %d\n", count1, count2);
	
	// Precision and width tests
	count1 = ft_printf("Width 10, right-aligned: %10d\n", 42);
	count2 = printf("Width 10, right-aligned: %10d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Width 10, left-aligned: %-10d\n", 42);
	count2 = printf("Width 10, left-aligned: %-10d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Left-justified: %-10s\n", "hello");
	count2 = printf("Left-justified: %-10s\n", "hello");
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Precision 4, zero-padded: %04d\n", 42);
	count2 = printf("Precision 4, zero-padded: %04d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Precision for string: %.5s\n", "abcdefg");
	count2 = printf("Precision for string: %.5s\n", "abcdefg");
	printf("%d = %d\n", count1, count2);

	// Combination of flags
	count1 = ft_printf("Combination: %-10.5d\n", 42);
	count2 = printf("Combination: %-10.5d\n", 42);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Zero-padded and width: %010x\n", 255);
	count2 = printf("Zero-padded and width: %010x\n", 255);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Zero-padded: %010d\n", 42);
	count2 = printf("Zero-padded: %010d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Positive sign flag: %+d\n", 42);
	count2 = printf("Positive sign flag: %+d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Space flag: % d\n", 42);
	count2 = printf("Space flag: % d\n", 42);
	printf("%d = %d\n", count1, count2);

	// Edge cases with precision and width
	count1 = ft_printf("Zero precision integer: %.0d\n", 0);
	count2 = printf("Zero precision integer: %.0d\n", 0);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Zero width and zero-padded: %0d\n", 0);
	count2 = printf("Zero width and zero-padded: %0d\n", 0);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Negative precision: %.d\n", 42);
	count2 = printf("Negative precision: %.d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Precision: %.5x\n", 255);
	count2 = printf("Precision: %.5x\n", 255);
	printf("%d = %d\n", count1, count2);

	// Large numbers and edge cases for width
	count1 = ft_printf("Width for large int: %20d\n", INT_MAX);
	count2 = printf("Width for large int: %20d\n", INT_MAX);
	printf("%d = %d\n", count1, count2);
	
	count1 = ft_printf("Width for large negative int: %20d\n", INT_MIN);
	count2 = printf("Width for large negative int: %20d\n", INT_MIN);
	printf("%d = %d\n", count1, count2);

	// Complex strings and special characters
	count1 = ft_printf("Escape sequences: %s\n", "Line1\nLine2\tTab\\Backslash");
	count2 = printf("Escape sequences: %s\n", "Line1\nLine2\tTab\\Backslash");
	printf("%d = %d\n", count1, count2);

	// # flag
	count1 = ft_printf("Alt form hex: %#x\n", 255);
	count2 = printf("Alt form hex: %#x\n", 255);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Alt form hex: %#X\n", 255);
	count2 = printf("Alt form hex: %#X\n", 255);
	printf("%d = %d\n", count1, count2);

	// + flag
	count1 = ft_printf("Plus flag: %+d\n", 42);
	count2 = printf("Plus flag: %+d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Plus flag: %+i\n", -42);
	count2 = printf("Plus flag: %+i\n", -42);
	printf("%d = %d\n", count1, count2);

	// space flag
	count1 = ft_printf("Space flag: % d\n", 42);
	count2 = printf("Space flag: % d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Space flag: % i\n", -42);
	count2 = printf("Space flag: % i\n", -42);
	printf("%d = %d\n", count1, count2);

	// Minimum field width
	count1 = ft_printf("Min width: %10d\n", 42);
	count2 = printf("Min width: %10d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Min width: %10s\n", "hello");
	count2 = printf("Min width: %10s\n", "hello");
	printf("%d = %d\n", count1, count2);

	// Field width with padding using zeros
	count1 = ft_printf("Zero-padded min width: %010d\n", 42);
	count2 = printf("Zero-padded min width: %010d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Zero-padded min width: %010x\n", 255);
	count2 = printf("Zero-padded min width: %010x\n", 255);
	printf("%d = %d\n", count1, count2);

	// Maximum field width
	count1 = ft_printf("Max width: %50d\n", 42);
	count2 = printf("Max width: %50d\n", 42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Max width: %50s\n", "hello");
	count2 = printf("Max width: %50s\n", "hello");
	printf("%d = %d\n", count1, count2);

	// Edge cases with combination of flags
	count1 = ft_printf("Combination: %+010d\n", 42);
	count2 = printf("Combination: %+010d\n", 42);
	printf("%d = %d\n", count1, count2);

	// Edge cases with negative numbers
	count1 = ft_printf("Negative: %+d\n", -42);
	count2 = printf("Negative: %+d\n", -42);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Negative with space: % d\n", -42);
	count2 = printf("Negative with space: % d\n", -42);
	printf("%d = %d\n", count1, count2);

	// Edge cases with 0 and NULL pointers
	count1 = ft_printf("Pointer 0: %p\n", (void *)0);
	count2 = printf("Pointer 0: %p\n", (void *)0);
	printf("%d = %d\n", count1, count2);

	count1 = ft_printf("Pointer NULL: %p\n", NULL);
	count2 = printf("Pointer NULL: %p\n", NULL);
	printf("%d = %d\n", count1, count2);
}*/
