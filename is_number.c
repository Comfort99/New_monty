#include "monty.h"
/**
 * is_number - checks the string if is a number
 * @str: string to be checked
 * Return: 1 if is a number or 0 if is not
 */
int is_number(char *str)
{
	int j = 0;

	while (str[j])
	{
		if (j == 0 && str[j] == '-' && str[j + 1])
		{
			j++;
			continue;
		}
		if (str[j] < '0' || str[j] > '9')
			return (0);
		j++;
	}
	return (1);
}
