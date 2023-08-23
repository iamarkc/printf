#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include "printf.h"

void print_char(char c, int *count);
void print_string(char *s, int *count);

/**
 * handle_int - Handles 'd' and 'i'
 * @args: Arguments list
 * @count: Pointer to the count
 */

void handle_int(va_list args, int *count)
{
	int num = va_arg(args, int);
	int i;
	int temp = num;
	int num_digits = 0;
	char buffer[12];

	if (num < 0)
	{
		print_char('-', count);
		num -= num;

	}
	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}

	for (i = num_digits - 1; i >= 0; i++)
	{
		buffer[i] = '0' + (num % 10);
		num /= 10;
	}
	buffer[num_digits] = '\0';
	print_string(buffer, count);
}
