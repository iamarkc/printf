#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stddef.h>

int _putchar(char c);

void print_char(char c, int *count);
void print_string(char *s, int *count);
void process_percent(int *count);
const char *process_format(const char *format, va_list args, int *count);
int _printf(const char *format, ...);

#endif
