#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
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
	int printedChars = 0, int_value, uint_value;
	char currentChar, chr_value;
	const char *str_value;
	char *binary_value, *hexa_value;

	va_start(arg_l, format);
	while (*format != '\0')
	{
		currentChar = *format;
		format++;

		if (currentChar == '%')
		{
			char nextChar = *format++;

			switch(nextChar)
			{
				case '%':
					_putchar('%');
					printedChars++;
					break;
				case 'x':
					uint_value = va_arg(arg_l, unsigned int);
					hexa_value = i_to_hex(uint_value, 0);
					printedChars += print_string(hexa_value);
					break;
				case 'X':
					uint_value = va_arg(arg_l, unsigned int);
					hexa_value = i_to_hex(uint_value, 1);
					printedChars += print_string(hexa_value);
					break;
				case 'b':
					uint_value = va_arg(arg_l, unsigned int);
					binary_value = i_to_binary(uint_value);
					printedChars += print_string(binary_value);
					break;
				case 'd':
					int_value = va_arg(arg_l, int);
					printedChars += print_number(int_value);
					break;
				case 'i':
					int_value = va_arg(arg_l, int);
					printedChars += print_number(int_value);
					break;
				case 'u':
					uint_value = va_arg(arg_l, unsigned int);
					printedChars += print_unsigned_number(uint_value);
					break;
				case 'c':
					chr_value = (int) va_arg(arg_l, int);
					printedChars += _putchar(chr_value);
					break;
				case 's':
					str_value = (const char *) va_arg(arg_l, const char *);
					printedChars += print_string(str_value);
					break;
				default:
					_putchar(currentChar);
					_putchar(nextChar);
					printedChars+=2;
					break;
			}
		} else
		{
			_putchar(currentChar);
			printedChars++;
		}

	}
	va_end(arg_l);
	return (printedChars);
}
