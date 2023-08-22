#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 * 
 * Return: Number of characters written.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
