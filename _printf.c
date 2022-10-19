// #include "main.h"
// #include <stdlib.h>

// /**
//  * check_for_specifiers - checks if there is a valid format specifier
//  * @format: possible format specifier
//  *
//  * Return: pointer to valid function or NULL
//  */
// static int (*check_for_specifiers(const char *format))(va_list)
// {
// 	unsigned int i;
// 	print_t p[] = {
// 		{"c", print_c},
// 		{"s", print_s},
// 		{"i", print_i},
// 		{"d", print_d},
// 		{"u", print_u},
// 		{"b", print_b},
// 		{"o", print_o},
// 		{"x", print_x},
// 		{"X", print_X},
// 		{"p", print_p},
// 		{"S", print_S},
// 		{"r", print_r},
// 		{"R", print_R},
// 		{NULL, NULL}
// 	};

// 	for (i = 0; p[i].t != NULL; i++)
// 	{
// 		if (*(p[i].t) == *format)
// 		{
// 			break;
// 		}
// 	}
// 	return (p[i].f);
// }

// /**
//  * _printf - prints anything
//  * @format: list of argument types passed to the function
//  *
//  * Return: number of characters printed
//  */
// int _printf(const char *format, ...)
// {
// 	unsigned int i = 0, count = 0;
// 	va_list valist;
// 	int (*f)(va_list);

// 	if (format == NULL)
// 		return (-1);
// 	va_start(valist, format);
// 	while (format[i])
// 	{
// 		for (; format[i] != '%' && format[i]; i++)
// 		{
// 			_putchar(format[i]);
// 			count++;
// 		}
// 		if (!format[i])
// 			return (count);
// 		f = check_for_specifiers(&format[i + 1]);
// 		if (f != NULL)
// 		{
// 			count += f(valist);
// 			i += 2;
// 			continue;
// 		}
// 		if (!format[i + 1])
// 			return (-1);
// 		_putchar(format[i]);
// 		count++;
// 		if (format[i + 1] == '%')
// 			i += 2;
// 		else
// 			i++;
// 	}
// 	va_end(valist);
// 	return (count);
// }

#include "main.h"

/**
* _printf - function
* @format: string to print
*
* Description: function to print specifiers c, s, %, d, and i
* Return: printed chars
*/
int _printf(const char *format, ...)
{
	int printed_chars;

	test_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}

/**
* parser - function
* @format: string
* @f_list: struct
* @arg_list: struct
*
* Description: parse
* Return: integer
*/
int parser(const char *format, test_t f_list[], va_list arg_list)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
			else
				return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	}
	return (printed_chars);
}
