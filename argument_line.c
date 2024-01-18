#include "monty.h"
/**
 * argument_line - Initializes a pointer to arg_s structure
 */
void argument_line(void)
{
	commands = malloc(sizeof(arg_t));
	if (commands == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_commands();
		exit(EXIT_FAILURE);
	}
	commands->instruction = malloc(sizeof(instruction_t));
	if (commands->instruction == NULL)
	{
		fprint(stderr, "Error: malloc failed\n");
		free_commands();
		exit(EXIT_FAILURE);
	}
	commands->streamlet = NULL;
	commands->head = NULL;
	commands->line = NULL;
	commands->n_tokens = 0;
	commands->line_number = 0;
	commands->stack_length = 0;
	commands->stack = 1;
}
