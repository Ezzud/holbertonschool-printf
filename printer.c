#include <unistd.h>
#include "main.h"
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
 * print_unsigned_number - Print a number in the stdout
 * @i: The number to print
 * Return: Number of chars printed
 */
int print_unsigned_number(unsigned int i)
{
	int dig_count = get_int_digits(i);

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
