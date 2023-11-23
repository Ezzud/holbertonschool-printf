#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "main.h"
/**
 * handle_format - Handle the printf formatting
 * @arg_l: The va_list of the printf function
 * @nextChar: Char corresponding to the format type
 * Return: Number of printed chars
 */
int handle_format(va_list arg_l, char nextChar)
{
	int printedChars = 0;

	if (nextChar == '%')
	{
		printedChars += _putchar(nextChar);
	} else if (nextChar == 'x' || nextChar == 'X')
	{
		printedChars += print_string(_utoa(va_arg(arg_l, unsigned int), 
			16, isupper(nextChar) ? 0 : 1));
	} else if (nextChar == 'b')
	{
		printedChars += print_string(_utoa(va_arg(arg_l, unsigned int), 2, 0));
	} else if (nextChar == 'o')
	{
		printedChars += print_string(_utoa(va_arg(arg_l, unsigned int), 8, 0));
	} else if (nextChar == 'd' || nextChar == 'i')
	{
		printedChars += print_string(_itoa(va_arg(arg_l, int), 10));
	} else if (nextChar == 'u')
	{
		printedChars += print_string(_utoa(va_arg(arg_l, unsigned int), 10, 0));
	} else if (nextChar == 'c')
	{
		printedChars += _putchar((int) va_arg(arg_l, int));
	} else if (nextChar == 's')
	{
		char *text = va_arg(arg_l, char *);

		if (!text)
			text = "(null)";
		printedChars += print_string(text);
	} else
		printedChars += (_putchar('%') + _putchar(nextChar));
	va_end(arg_l);
	return (printedChars);
}
