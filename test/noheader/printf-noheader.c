#include <stdarg.h>
#include <unistd.h>
/**
 * get_int_digits - Get the number of digits of an int
 * @v: Integer to check
 * Return: Number of digits
 */
int get_int_digits(int v)
{
	int count = 0;
	int temp = v;

	if (temp < 0)
		count++;
	do {
		temp /= 10;
		++count;
	} while (temp != 0);
	return (count);
}
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
/**
 * print_number - Print a number in the stdout
 * @i: The number to print
 * Return: Number of chars printed
 */
int print_number(int i)
{
	int dig_count = get_int_digits(i);

	if (i < 0)
	{
		_putchar('-');
		i = -i;
	}
	if (i / 10)
		print_number(i / 10);
	_putchar(i % 10 + '0');
	return (dig_count);
}
/**
 * print_string - Print a string in the stdout
 * @str_value: The text to print
 * Return: Number of characters printed
 */
int print_string(const char *str_value)
{
	int i = 0;

	while (*str_value != '\0')
	{
		_putchar(*str_value);
		str_value++;
		i++;
	}
	return (i);
}
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
