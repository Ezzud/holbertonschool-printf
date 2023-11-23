#ifndef _PRINTF_
#define _PRINTF_
#include <stdarg.h>
int _printf(const char *format, ...);
int get_int_digits(int v);
int _putchar(char c);
int print_string(char *str_value);
char *i_to_hex(unsigned int num, int isUpper);
int handle_format(va_list arg_l, char nextChar);
int _abs(int n);
char *_itoa(int num, int base);
char *_reverse(char *s, int n);
char *_utoa(unsigned int num, unsigned int base);
#endif
