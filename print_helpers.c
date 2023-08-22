#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "printf.h"
#include "main.h"

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
