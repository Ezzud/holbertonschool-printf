#include <stdlib.h>
#include "main.h"
/**
 * _abs - Get the absolute num of a number
 * @n: the number to invert
 * Return: the absolute num
 */

int _abs(int n)
{
	if (n < 0)
	{
		n = n * -1;
		return (n);
	}
	return (n);
}
/**
 * *_reverse - Reverse a text
 * @s: Text to reverse
 * @n: Array length
 * Return: The reversed string
 */

char *_reverse(char *s, int n)
{
	int i, aux;

	n--;
	for (i = 0; i <= n; i++, n--)
	{
		aux = s[i];
		s[i] = s[n];
		s[n] = aux;
	}
	return (s);
}
/**
 * *_itoa - Convert int to string
 * @num: Number or num
 * @base: Base to convert
 * Return: Number converted to string
 */
char *_itoa(int num, int base)
{
	char buffer[1024];
	int n, i;

	if (base < 2 || base > 32)
		exit(1);
	n = _abs(num);
	i = 0;

	while (n)
	{
		int r = n % base;

		r = _abs(r);
		if (r >= 10)
			buffer[i] = 65 + (r - 10);
		else
			buffer[i] = 48 + r;
		i++;
		n = n / base;
	}

	if (i == 0)
	{
		buffer[i] = '0';
		i++;
	}
	if (num < 0 && base == 10)
	{
		buffer[i] = '-';
		i++;
	}
	buffer[i] = '\0';

	return (_reverse(buffer, i));
}
/**
 * *_utoa - Convert unsigned int to string
 * @num: Number to convert
 * @base: Base to convert
 * @forcelc: Force lowercase
 * Return: Converted string
 */
char *_utoa(unsigned int num, unsigned int base, int forcelc)
{
	char buffer[1024];
	unsigned int i, r;

	if (base < 2 || base > 32)
		exit(1);
	i = 0;

	while (num)
	{
		r = num % base;

		if (r >= 10)
		{
			buffer[i] = 65 + (r - 10);
			if(forcelc > 0)
			{
				if (buffer[i] >= 65 && buffer[i] <= 90)
				buffer[i] += 32;
			}
		} else
			buffer[i] = 48 + r;

		i++;
		num = num / base;
	}
	if (i == 0)
	{
		buffer[i] = '0';
		i++;
	}
	buffer[i] = '\0';

	return (_reverse(buffer, i));
}
