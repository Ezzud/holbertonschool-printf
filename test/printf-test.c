#include <stdarg.h>
#include "printf.h"
/*
 * _printf - Format a text and print it
 * @format: Original string to be formatted
 *
 * Return: Number of printed characters
 */
int _printf(const char* format, ...)
{
	va_list arg_l;
	int printedChars = 0;
	char currentChar;

	va_start(arg_l, format);
	while ( *format != '\0')
	{
		currentChar = *format;
		format++;

		/*
		 * Check if char is a starts of formatting parameter
		 */
		if ( currentChar == '%' )
		{
			char nextChar = *format++;
			/*
			 * Check if parameter is a int
			 */
			if (nextChar == 'd')
			{
				int int_value = (int) va_arg( arg_l, int );
				printedChars+=print_number(int_value);
			}
			/*
			 *  Check if parameter is a string 
			 */
			else if (nextChar == 's')
			{
				const char *str_value = (const char *) va_arg( arg_l, const char *);
				printedChars += print_string(str_value);
			} else {
				/*
				 * Error detected (no recognized parameter)
				 */
			}
		} else {
			_putchar(currentChar);
			printedChars++;
		}


	}
	return printedChars;
}