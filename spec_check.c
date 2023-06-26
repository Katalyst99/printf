#include "main.h"

/**
 * spec_check - checks for an appropriate specifier and  assigns
 * an appropriate function for it
 * @fmat: The specifier
 * Return: A pointer to function
 */
int (*spec_check(char fmat))(va_list)
{
	int i;

	dtfnc_t arr[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_i},
		{'i', print_i},
		{'\0', NULL}
	};

	for (i = 0; arr[i].type; i++)
	{
		if (arr[i].type == fmat)
		{
			return (arr[i].f);
		}
	}
	return (NULL);
}
