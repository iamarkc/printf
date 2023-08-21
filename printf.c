#include <stdio.h>
#include <stdarg.h>

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
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else
			{
				putchar(*format);
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
