#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of the printf function.
 * @format: Format string containing conversion specifiers.
 * ...: Additional arguments to be formatted and printed.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	const char *ptr = format;

	va_start(args, format);

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'd' || *ptr == 'i')
			{
				int num = va_arg(args, int);

				printf("%d", num);
				count += snprintf(NULL, 0, "%d", num);
			}
			else
			{
				putchar(*ptr);
				count++;
			}
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
