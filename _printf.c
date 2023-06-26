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
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			fnc = spec_check(format[i + 1]);
			if (fnc !=  NULL)
			{
				c += fnc(ap);
				i = i + 2;
				continue;
			}
			if (format[i + 1] != '\0')
			{
				_putchar(format[i + 1]);
				c++;
				i += 2;
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			_putchar(format[i]);
			c++;
			i++;
			continue;
		}
	}
	va_end(ap);
	return (c);
}
