#include "monty.h"
/**
 * get_path - gets the path of the file being specified.
 * @fileName: Name of the file to open and set as the path
 */
void get_path(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		free_commands();
		exit(EXIT_FAILURE);
	}
	commands->path = fdopen(fd, "r");
	if (commands->path == NULL)
	{
		close(fd);
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		free_commands();
		exit(EXIT_FAILURE);
	}
}
