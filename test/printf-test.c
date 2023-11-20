#include <stdarg.h>
#include "printf.h"
/**
 * _printf - Format a text and print it
 * @format: Original string to be formatted
 *
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list arg_l;
	int printedChars = 0, int_value;
	char currentChar, chr_value;

	va_start(arg_l, format);
	while (*format != '\0')
	{
		currentChar = *format;
		format++;

		if (currentChar == '%')
		{
			char nextChar = *format++;

			if (nextChar == 'd')
			{
				int_value = (int) va_arg(arg_l, int);
				printedChars += print_number(int_value);
			} else if (nextChar == 'i')
			{
				int_value = (int) va_arg(arg_l, int);
				printedChars += print_number(int_value);
			} else if (nextChar == 'c')
			{
				chr_value = (int) va_arg(arg_l, int);
				printedChars += _putchar(chr_value);
			} else if (nextChar == 's')
			{
				const char *str_value = (const char *) va_arg(arg_l, const char *);

				printedChars += print_string(str_value);
			}
		} else
		{
			_putchar(currentChar);
			printedChars++;
		}
		va_end(arg_l);
	}
	return (printedChars);
}
