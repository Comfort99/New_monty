#include "monty.h"
/**
 * get_streamlet - gets the streamlet of the file being specified.
 * @fileName: Name of the file to open and set as the streamlet
 */
void get_streamlet(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		free_commands();
		exit(EXIT_FAILURE);
	}
	commands->streamlet = fdopen(fd, "r");
	if (commands->streamlet == NULL)
	{
		close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		free_commands();
		exit(EXIT_FAILURE);
	}
}
