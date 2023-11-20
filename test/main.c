#include "printf.h"
#include <stdio.h>
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define CHECK "\xE2\x9C\x85"
#define CROSS "\xE2\x9D\x8C"
int main()
{
	int result1, result2, result3, result4, result5, result6;

	result1 = _printf("Chiffre Positif: %d", 5);
	printf("$ | Char count: %d\n", result1);

	result2 = _printf("Chiffre Negatif: %d", -9);
	printf("$ | Char count: %d\n", result2);

	result3 = _printf("Nombre Positif: %d", 666565);
	printf("$ | Char count: %d\n", result3);

	result4 = _printf("Nombre Negatif: %d", -5377);
	printf("$ | Char count: %d\n", result4);

	result5 = _printf("String: %s", "Ceci est un texte accentué");
	printf("$ | Char count: %d\n", result5);

	result6 = _printf("String vide: %s", "");
	printf("$ | Char count: %d\n", result6);

	printf("\nResults:\n");
	if(result1 == 18)
		printf("  %s%s %sTest #1 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #1 Failed\n", RED, CROSS, RESET);

	if(result2 == 19)
		printf("  %s%s %sTest #2 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #2 Failed\n", RED, CROSS, RESET);

	if(result3 == 22)
		printf("  %s%s %sTest #3 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #3 Failed\n", RED, CROSS, RESET);

	if(result4 == 21)
		printf("  %s%s %sTest #4 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #4 Failed\n", RED, CROSS, RESET);

	if(result5 == 35)
		printf("  %s%s %sTest #5 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #5 Failed\n", RED, CROSS, RESET);

	if(result6 == 13)
		printf("  %s%s %sTest #6 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #6 Failed\n", RED, CROSS, RESET);

	return(1);
}