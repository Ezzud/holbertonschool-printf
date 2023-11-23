#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Format a text and print it
 * @format: Original string to be formatted
 *
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int printedChars = 0;
	char currentChar;
	va_list arg_l;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		exit(1);
	va_start(arg_l, format);
	while (*format != '\0')
	{
		currentChar = *format;
		format++;
		if (currentChar == '%')
		{
			char nextChar = *format++;

			printedChars += handle_format(arg_l, nextChar);
		} else
			printedChars += _putchar(currentChar);
	}
	return (printedChars);
}
