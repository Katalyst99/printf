#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int (*spec_check(char fmat))(va_list);
int print_c(va_list ap);
int print_s(va_list ap);
int print_i(va_list ap);
int print_pct(va_list ap);
/**
 * struct dtfnc - struct type dtfnc
 * @type : The type
 * @f: The function pointer to a function that prints
 */
typedef struct dtfnc
{
	char type;
	int (*f)(va_list);
} dtfnc_t;

#endif
