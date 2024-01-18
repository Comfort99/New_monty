#include "monty.h"
/**
 * is_number - checks the string if is a number
 * @str: string to be checked
 * Return: 1 if is a number or 0 if is not
 */
int is_number(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
