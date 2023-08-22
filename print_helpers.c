#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "printf.h"
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
	char c = (char)va_arg(args, int);
	char *s = va_arg(args, char *);

	format++;
	if (*format == '\0')
		return (format);
	if (*format == 'c')
	{
		print_char(c, count);
	}
	else if (*format == 's')
	{
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
