#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
void process_percent(int *count);
void print_char(char c, int *count);
void print_string(char *s, int *count);
const char *process_format(const char *format, va_list args, int *count);

#endif
