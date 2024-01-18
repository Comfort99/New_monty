#include "monty.h"
/**
 * close_streamlet - Closes the file stream and sets it to NULL.
 */
void close_streamlet(void)
{
	if (commands->streamlet == NULL)
		return;

	fclose(commands->streamlet);
	commands->streamlet = NULL;
}
