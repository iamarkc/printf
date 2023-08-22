#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

void process_percent(int *count);
void print_char(char c, int *count);
void print_string(char *s, int *count);
void process_percent(int *count);

void print_integer(int num, int *count);
void process_d(va_list args, int *count);

int _putchar(char c);
void print_binary(unsigned int n, int *count);
int _printf(const char *format, ...);
const char *process_format(const char *format, va_list args, int *count);

#endif
