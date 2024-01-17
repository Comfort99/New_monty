#include "monty.h"
/**
 * mian - Entry point
 * @argc: The number of commands
 * @argv: The pointer to array of strings containing arguments
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	(void) argv;

	if (argc != 2)
	{
		fprint(stderr, "USAGE: monty file")
			return (EXIT_FAILURE);
	}
	return (0);
}
