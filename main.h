#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);

/**
  *struct  Special_chr - all special charectors
  *@chr: special charector
  *@f: function
  */

typedef struct special_chr
{
	char *chr;
	int (*f)(va_list);
special_chr;
}


