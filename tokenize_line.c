#include "monty.h"
/**
 * tokenize_line - Tokenizes the line read from file.
 */
void tokenize_line(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *strdup = NULL;

	strdup = malloc(sizeof(char) * (strlen(commands->line) + 1));
	strcpy(strdup, commands->line);

	commands->n_tokens = 0;
	token = strtok(strdup, delims);

	while (token)
	{
		commands->n_tokens += 1;
		commands->tokens = realloc(commands->tokens,
				sizeof(char *) * (commands->n_tokens + 1));
		if (commands->tokens == NULL)
		{
			fprintf(stderr, "Error reallocating memory.\n");
			exit(1);
		}
		commands->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (commands->tokens[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_commands();
			exit(EXIT_FAILURE);
		}
		strcpy(commands->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	commands->tokens[i] = NULL;
	free(strdup);
}
