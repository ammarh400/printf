#include "main.h"

/**
 *print_char - print a char
 *
 *@ptr: pointer
 *Return: int
 */

int print_char(va_list ptr)
{
	char c = va_arg(ptr, int);

	return (write(1, &c, 1));
}

/**
 *print_string - print a string to the stdout
 *
 *@str: pointer to va_list
 *Return: int
 */
int print_string(va_list str)
{
	char *s;

	s = va_arg(str, char*);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, s, strlen(s));
	}
	return (strlen(s));
}
/**
 *print_int - print an integer
 *
 *@ptr: pointer to va_list
 *Return: int
 */

int print_int(va_list ptr)
{
	long int num;
	int count = 0;
	int printed_int;
	int base;

	num = va_arg(ptr, int);

	if (num < 0)
	{
		num *= -1;
		_putchar('-');
		count++;
	}
	if (num >= 0 && num <= 9)
	{
		_putchar(num + '0');
		count++;
	}
	if (num > 9)
	{
		base = 10;

		while (num / base > 9)
		{
			base *= 10;
		}

		while (base > 0)
		{
			printed_int = num / base;
			num = num % base;
			_putchar(printed_int + '0');
			base = base / 10;
			count++;
		}
	}
	return (count);
}

/**
 *_putchar - function to print a single char to the stdout
 *
 *@c: char to be printed
 *Return: int
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
