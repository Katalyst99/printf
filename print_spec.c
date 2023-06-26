#include "main.h"

/**
 * print_c - prints a character
 * @ap: arguments pointing to the character
 * Return: Number of characters printed (1)
 */
int print_c(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	_putchar(c);
	return (1);
}

/**
 * print_s - prints a string
 * @ap: arguments pointing to the string
 * Return: Number of characters printed
 */
int print_s(va_list ap)
{
	char *s;
	int i;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		s = "(null)";
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
	return (i);
}

/**
 * print_i - Prints an integer
 * @ap: arguments pointing to the integer
 * Return: Number of characters printed
 */
int print_i(va_list ap)
{
	unsigned int d;
	int n, i = 1, c = 0;

	n = va_arg(ap, int);

	if  (n < 0)
	{
		d = -(n);
		_putchar('-');
		c++;
	}
	else
		d = n;

	for (; (d / i) > 9; )
	{
		i =  i * 10;
	}

	while (i >= 1)
	{
		_putchar(((d / i) % 10) + '0');
		i = i / 10;
		c++;
	}
	return (c);
}

/**
 * print_pct - prints percentage character
 * @ap: arguments pointing to the character
 * Return: Number of characters printed
 */
int print_pct(va_list ap)
{
	(void)ap;

	_putchar('%');
	return (1);
}
