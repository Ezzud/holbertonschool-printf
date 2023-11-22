#include "printf.h"
#include <stdio.h>
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"
#define CHECK "\xE2\x9C\x85"
#define CROSS "\xE2\x9D\x8C"
int main()
{
	int firstresult, result1, result2, result3, result4, result5, result6, result7, result8, result9, result10, result11;

	firstresult = _printf("Message basique");
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, firstresult);

	result1 = _printf("Chiffre Positif: %d", 5);
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result1);

	result2 = _printf("Chiffre Negatif: %d", -9);
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result2);

	result3 = _printf("Nombre Positif: %d", 666565);
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result3);

	result4 = _printf("Nombre Negatif: %d", -5377);
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result4);

	result5 = _printf("String: %s", "Ceci est un texte accentué");
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result5);

	result6 = _printf("String vide: %s", "");
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result6);

	result7 = _printf("Char sous HEX: %c", 48);
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result7);

	result8 = _printf("Char: %c", 'd');
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result8);

	result9 = _printf("Char: %c", 'C');
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result9);

	result10 = _printf("Unknown: %r", "rrgr");
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result10);

	result11 = _printf("Binary: %b", "52");
	printf("%s$%s | Char count: %d\n", YELLOW, RESET, result11);

	printf("\nResults:\n");
	if(firstresult == 15)
		printf("  %s%s %sTest #0 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #0 Failed\n", RED, CROSS, RESET);

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

	if(result7 == 16)
		printf("  %s%s %sTest #7 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #7 Failed\n", RED, CROSS, RESET);

	if(result8 == 7)
		printf("  %s%s %sTest #8 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #8 Failed\n", RED, CROSS, RESET);

	if(result9 == 7)
		printf("  %s%s %sTest #9 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #9 Failed\n", RED, CROSS, RESET);

	if(result10 == 11)
		printf("  %s%s %sTest #10 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #10 Failed\n", RED, CROSS, RESET);

	if(result11 == 14)
		printf("  %s%s %sTest #11 Successfull\n", GREEN, CHECK, RESET);
	else
		printf("  %s%s %sTest #11 Failed\n", RED, CROSS, RESET);

	return(1);
}