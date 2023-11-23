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
		printedChars += print_string(i_to_hex(va_arg(arg_l, unsigned int),
			isupper(nextChar) ? 1 : 0));
	} else if (nextChar == 'b')
	{
		printedChars += print_string(i_to_binary(va_arg(arg_l, unsigned int)));
	} else if (nextChar == 'd' || nextChar == 'i')
	{
		printedChars += print_string(_itoa(va_arg(arg_l, int), 10));
	} else if (nextChar == 'u')
	{
		printedChars += print_string(_utoa(va_arg(arg_l, unsigned int), 10));
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
 * i_to_binary - Convert an unsigned int to binary
 * @x: The number to convert
 * Return: The binary number as a string
 */
char *i_to_binary(unsigned int x)
{
	int binaryNum[32];
	char *binaryText = malloc(sizeof(char) * 32);
	int i = 0, j;

	if (x == 0)
		return (0);
	for (; x > 0;)
	{
		binaryNum[i++] = x % 2;
		x /= 2;
	}
	for (j = i - 1; j >= 0; j--)
		binaryText[i - (j + 1)] = binaryNum[j] + '0';
	return (binaryText);
}
/**
 * i_to_hex - Convert an unsigned int to hexadecimal
 * @num: The number to convert
 * @isUpper: If letter are in uppercase
 * Return: The hexadecimal number as a string
 */
char *i_to_hex(unsigned int num, int isUpper)
{
	int len;
	char *hex, *hex2;
	char upperhex[17] = "0123456789ABCDEF", lowerhex[17] = "0123456789abcdef";

	len = num & 0xFFFF0000 ?
	(num & 0xFF000000 ?
		(num & 0xF0000000 ? 8 : 7) :
		(num & 0x00F00000 ? 6 : 5)) : (num & 0x0000FF00 ?
		(num & 0x0000F000 ? 4 : 3) : (num & 0x000000FF ?
			(num & 0x000000F0 ? 2 : 1) : 1));
	hex = malloc((len + 1) * sizeof(char)), hex2 = hex + len;
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
