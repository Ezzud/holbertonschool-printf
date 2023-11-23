#ifndef _PRINTF_
#define _PRINTF_
#include <stdarg.h>
int _printf(const char *format, ...);
int get_int_digits(int v);
int _putchar(char c);
int print_number(int i);
int print_string(const char *str_value);
int print_unsigned_number(unsigned int i);
char *i_to_binary(unsigned int i);
char *i_to_hex(unsigned int num, int isUpper);
int handle_format(va_list arg_l, char nextChar);
#endif
