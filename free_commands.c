#include "monty.h"
/**
 * free_head - Frees the memory allocated for the head and
 * sets it to NULL.
 */
void free_head(void)
{
	if (commands->head)
		free_stack(commands->head);

	commands->head = NULL;
}
/**
* free_commands - free memory allocated to commands pointer
*/
void free_commands(void)
{
	if (commands == NULL)
		return;

	if (commands->instruction)
	{
		free(commands->instruction);
		commands->instruction = NULL;
	}

	free_head();

	if (commands->line)
	{
		free(commands->line);
		commands->line = NULL;
	}
	free(commands);
}
