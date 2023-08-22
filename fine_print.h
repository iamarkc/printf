#ifndef FINE_PRINT_H
#define FINE_PRINT_H

#include <stdarg.h>

void print_int(int num, int *count);
void process_fmt(const char *format, va_list args, int *count);
int custom_printf(const char *format, ...);

#endif
