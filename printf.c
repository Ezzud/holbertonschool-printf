#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
/**
 * _printf - Format a text and print it
 * @format: Original string to be formatted
 *
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list arg_l;
	int printedChars = 0;
	char currentChar;

	va_start(arg_l, format);
	while (*format != '\0')
	{
		currentChar = *format;
		format++;

		if (currentChar == '%')
		{
			char nextChar = *format++;

			switch (nextChar)
			{
				case '%':
					printedChars += _putchar(nextChar);
					break;
				case 'x':
				case 'X':
					printedChars += print_string(i_to_hex(va_arg(arg_l, unsigned int), isupper(nextChar) ? 1 : 0));
					break;
				case 'b':
					printedChars += print_string(i_to_binary(va_arg(arg_l, unsigned int)));
					break;
				case 'd':
				case 'i':
					printedChars += print_number(va_arg(arg_l, int));
					break;
				case 'u':
					printedChars += print_unsigned_number(va_arg(arg_l, unsigned int));
					break;
				case 'c':
					printedChars += _putchar((int) va_arg(arg_l, int));
					break;
				case 's':
					printedChars += print_string((const char *) va_arg(arg_l, const char *));
					break;
				default:
					printedChars += (_putchar(currentChar) + _putchar(nextChar));
					break;
			}
		} else
			printedChars += _putchar(currentChar);
	}
	va_end(arg_l);
	return (printedChars);
}
