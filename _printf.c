#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - prints formatted string
 * @format: The string
 * Return: The number of printed characters
 */
int _printf(const char *format, ...)
{
	int i = 0, c = 0;
	va_list ap;
	int (*fnc)(va_list);

	va_start(ap, format);

	if (format == NULL)
	{
		return (-1);
	}

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				c += _putchar('%');
				i++;
			}
			fnc = spec_check(format[i + 1]);
			if (fnc != NULL)
			{
				c  += fnc(ap);
				i = i + 2;
			}
			if (format[i + 1] == '\0')
				return (-1);

		}
		else
		{
			_putchar(format[i]);
			c++;
		}
		i++;

	}
	va_end(ap);
	return (c);
}
