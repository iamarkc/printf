#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "printf.h"
#include "main.h"

/**
 * print_integer - Prints an integer.
 * @num: Integer printed.
 * @count: Pointer to the count of characters.
 */

void print_integer(int num, int *count)
{
	int divisor = 1;
	int temp = num;
	int digit = num / divisor;

	if (num < 0)
	{
		print_char('-', count);
		num = -num;
	}
	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}
	while (divisor > 0)
	{

		print_char('0' + digit, count);
		num %= divisor;
		divisor /= 10;
	}
}

/**
 * process_d - Handles d conversion.
 * @args: Arguments list.
 * @count: Pointer to the of characters.
 */
void process_d(va_list args, int *count)
{
	int num  = va_arg(args, int);

	print_integer(num, count);
}
