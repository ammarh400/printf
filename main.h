#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 *struct printf - structure to handle printf functions
 *@ch: char
 *@ptr: pointer to function that takes va_list and return an int
 */

typedef struct printf
{
	char ch;
	int (*ptr)(va_list);
} printf_struct;

int _printf(const char *format, ...);
int (*compare_fun(const char c))(va_list);
int print_char(va_list ptr);
int print_string(va_list str);
int print_int(va_list ptr);
int _putchar(char c);


#endif
