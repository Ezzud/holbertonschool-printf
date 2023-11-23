#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
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
 * i_to_binary - Convert an unsigned int to binary
 * @i: The number to convert
 * Return: The binary number as a string
 */
char *i_to_binary(unsigned int x)
{
	int binaryNum[32];
	char *binaryText = malloc(sizeof(char) * 32);
   	int i=0;
   	int j;

	if (x == 0)
		return (0);

	for (;x > 0;)
	{
    	binaryNum[i++] = x % 2;
		x /= 2;
   	}
   	for (j = i-1; j >= 0; j--)
		binaryText[i-(j+1)] = binaryNum[j] + '0';
   	return (binaryText);
}
/**
 * i_to_hex - Convert an unsigned int to hexadecimal
 * @num: The number to convert
 * @isUpper: If letter are in uppercase
 * Return: The hexadecimal number as a string
 */
char *i_to_hex(unsigned num, int isUpper)
{
	int len;
	char *hex, *hex2;
	char upperhex[17] = "0123456789ABCDEF", lowerhex[17] = "0123456789abcdef";

	len = num & 0xFFFF0000 ? (num & 0xFF000000 ? (num & 0xF0000000 ? 8 : 7) : (num & 0x00F00000 ? 6 : 5)) : (num & 0x0000FF00 ? (num & 0x0000F000 ? 4 : 3) : (num & 0x000000FF ? (num & 0x000000F0 ? 2 : 1) : 1));
	hex = malloc((len+1)*sizeof(char)), hex2 = hex+len;
	for (--hex2; ; hex2--)
	{
		if (isUpper)
			*hex2 = upperhex[num & 0xF];
		else
			*hex2 = lowerhex[num & 0xF];
		num >>= 4;
		if (num == 0)
			break;
	}
	return (hex2);
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
