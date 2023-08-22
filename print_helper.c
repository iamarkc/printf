#include <stdio.h>
#include <stdarg.h>
#include "printf.h"
#include "main.h"

/**
 * handle_d_and_i - Custom implementation of printf function.
 * @format: Format string.
 * @count: Pointer to the count.
 *
 * Return: Number of characters printed.
 */

int handle_d_and_i(const char *format, ...)
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
				count += printf(NULL, 0, "%d", num);
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
