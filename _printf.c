#include "main.h"

/**
 *_printf - function to handle s, c and %
 *
 *@format: pointer to const char
 *Return: number of ther printed characters
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, print_char = 0;
	va_list ptr;

	if (format == NULL)
		return (-1);

	va_start(ptr, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
		write(1, &format[i], 1);
		print_char++;
		}
		else
		{
			if (format[i + 1] == '\0')
				return (-1);

			else if (format[i + 1] == '%')
			{
				_putchar('%');
				print_char++;
				i++;
			}
			else if (compare_fun(format[i + 1]) != NULL)
			{
				print_char += (compare_fun(format[i + 1]))(ptr);
				i++;
			}
			else
			{
				write(1, &format[i], 1);
				print_char++;
			}
		}
	}
	va_end(ptr);
	return (print_char);
}

/**
 *compare_fun - function to determine which sybmol to be printed
 *@c: const char to compare
 *
 *Return: a pointer to function that takes a va_list and return an int
 */
int (*compare_fun(const char c))(va_list)
{
	int i;
	printf_struct arr[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
		};

	for (i = 0; arr[i].ch != '\0'; i++)
	{
		if (arr[i].ch == c)
		{
			return (arr[i].ptr);
		}
	}
	return (NULL);
}
