#include "main.h"

/**
 * _printf - Printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	va_list list;

	if (format == NULL)
	return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
		write(1, &format[i], 1);
		printed_chars++;
		}
	else
		{
		i++;
		va_arg(list, void *);
		write(1, " ", 1);
		printed_chars++;
		}
	}

	va_end(list);

	return (printed_chars);
}

