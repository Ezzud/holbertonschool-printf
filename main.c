#include "printf.h"
#include <stdio.h>
int main()
{
	int result1 = _printf("Nombre: %d", 500);
	printf("%d\n", result1);
	return(1);
}