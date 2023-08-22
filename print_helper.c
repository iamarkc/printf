#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of the printf function.
 * @format: Format string containing conversion specifiers.
 * @...: Additional arguments to be formatted and printed.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
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
				count++;
			}
			else if (*ptr == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(*ptr);
				count += 2;
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
