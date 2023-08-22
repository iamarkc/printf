#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

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
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = process_format(format, args, &count);
		}
		else
		{
			print_char(*format, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}
