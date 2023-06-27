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
			fnc = spec_check(spec);
			if (fnc != NULL)
			{
				c += fnc(ap);
				i += 2;
				continue;
			}
			else
			{
				i++;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			c++;
			i++;
			continue;
		}
		if (format[i] != '\0')
			return (-1);
	}
	va_end(ap);
	return (c);
}
