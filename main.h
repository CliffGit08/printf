#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *print;
	int (*p)();
} print_t;

int _printf(const char *format, ...);
int _putchar(char c);
int p_char(va_list arg);
int p_str(va_list arg);
int p_dec(va_list arg);
int p_int(va_list arg);

#endif  /* _MAIN_H */
