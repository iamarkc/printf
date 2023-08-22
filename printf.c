#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"

/**
 * process_format - Processes a single format.
 * @format: Pointer to the current format.
 * @args: Argument list.
 * @count: Pointer to the count of characters printed.
 *
 * Return: Pointer to the format string.
 */

const char *process_format(const char *format, va_list args, int *count)
{
	format++;
	if (*format == '\0')
		return (format);

	if (*format == 'c')
	{
	char c = (char)va_arg(args, int);

	print_char(c, count);
	}
	else if (*format == 's')
	{
		char *s = va_arg(args, char *);

		print_string(s, count);
	}
	else if (*format == '%')
	{
		process_percent(count);
	}
	else if (*format == 'd' || *format == 'i')
	{
		process_d(args, count);
	}
	else
	{
		print_char('%', count);
		print_char(*format, count);
	}
	return (format);
}

/**
 * print_binary - Prints the binary represantation.
 * @n: The unsigned int to be printed.
 * @count: Pointer to the count of characters.
 */

void print_binary(unsigned int n, int *count)
{
        if (n / 2 != 0)
	{
		print_binary(n / 2, count);
	}
		*count += _putchar('0' + n % 2);
}

/**
 * _printf - Produces the output according to a format.
 * @format: Character string.
 *	c:
 *	s:
 *	%:
 * @...: Additional arguments to be formatted.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;
	unsigned int num = va_arg(args, unsigned int);

	va_start(args, format);
	ptr = format;

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
		}
		else if (*ptr == 'b')
		{
			print_binary(num, &count);
			ptr++;
		}
		else
		{
			putchar('%');
			putchar(*ptr);
		}
		ptr++;
	}
	va_end(args);
	return (count);
}
