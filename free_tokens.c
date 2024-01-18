#include "monty.h"
/**
 * free_tokens - Frees the allocated memory for tokens.
 */
void free_tokens(void)
{
	int j = 0;

	if (commands->tokens == NULL)
		return;
	while (commands->tokens[j])
	{
		free(arguments->tokens[j]);
		i++;
	}
	free(commands->tokens);
	commands->tokens = NULL;
}
