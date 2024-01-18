#include "monty.h"

arg_t *commands = NULL;

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
		fprintf(stderr, "USAGE: monty file")
			return (EXIT_FAILURE);
	}
	argument_line();
	get_streamleti(arg[1]);
	
	while(getline(&commands->line, &n, commands->streamlet) != -1)
	{
		commands->line_number += 1;
		tokenize();
		get_instruction();
		run_instruction();
		free_token();
	}
	close_streamlet();
	free_commands();
	return (0);
}
