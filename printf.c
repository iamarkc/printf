#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * print_char - Prints a single character.
 * @c: The character to be printed.
 * @count: Pointer to the count of characters.
 */

void print_char(char c, int *count)
{
	putchar(c);
	(*count)++;
}

/**
 * print_string - Prints a string.
 * @s: The string to be printed.
 * @count: Pointer to the count of characters.
 */

void print_string(char *s, int *count)
{
	if (s == NULL)
	{
		char *nullString = "(null)";

		while (*nullString)
		{
			putchar(*nullString);
			nullString++;
			(*count)++;
		}
	}
	else
	{
		while (*s)
		{
			putchar(*s);
			s++;
			(*count)++;
		}
	}
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

				print_char(c, &count);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				print_string(s, &count);
			}
			else
			{
				print_char(*format, &count);
			}
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
