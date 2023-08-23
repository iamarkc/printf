#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * print_char - Prints a single character.
 * @c: The character to be printed.
 * @count: Pointer to the count of characters.
 */

void print_char(char c, int *count)
{
	write(1, &c, 1);
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
			write(1, nullString, 1);
			nullString++;
			(*count)++;
		}
	}
	else
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
			(*count)++;
		}
	}
}

/**
 * process_percent - Handles the '%' format.
 * @count: Pointer to the count of characters printed.
 *
 * Return: -1 to indicate error.
 */

void process_percent(int *count)
{
	print_char('%', count);
}

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
	else
	{
		print_char('%', count);
		print_char(*format, count);
	}
	return (format);
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

	if (format == NULL)
	{
		return (-1);
	}

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
