#include <unistd.h>
#include <stdarg.h>
#include "printf.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/*
 * _printf - Format a text and print it
 * @format: Original string to be formatted
 *
 * Return: Number of printed characters
 */
int _printf(const char* format, ...)
{
	va_list arg_l;
	size_t printedChars = 0;
	char currentChar;

	va_start(arg_l, format);
	while ( (currentChar = *format) != '\0')
	{
		format++;
		if ( currentChar != '%' )
		{
			_putchar(currentChar);
			printedChars++;			
		}
	}
	return printedChars;
}