#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * print_int - Prints an integer.
 * @num: Integer to be printed.
 * @count: Pointer to the count of characters.
 */

void print_int(int num, int *count)
{
	printf("%d", num);
	(*count)++;
}

/**
 * process_fmt - Processes a single format
 * @format: Pointer to the format.
 * @args: Arguments list.
 * @count: Pointer to the count.
 */

void process_fmt(const char *format, va_list args, int *count)
{
	format++;
	if (*format == '\0')
		return;
	if (*format == 'd' || *format == 'i')
	{
		int num = va_arg(args, int);

		print_int(num, count);
	}
	else
	{
		putchar('%');
		putchar(*format);
		(*count) += 2;
	}
}

/**
 * custom_printf - Custom implementation of the printf function.
 * @format: Format string containing specifiers.
 * @...: Additional arguments.
 *
 * Return: Number of characters to be printed.
 */

int custom_printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	const char *ptr = format;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			process_fmt(ptr, args, &count);
			while (*ptr != '\0' && *ptr != 'd' && *ptr != 'i')
				ptr++;
		}
		else
		{
			putchar(*ptr);
			count++;
		}
		ptr++;
	}
	va_end(args);
	return (count);
}
