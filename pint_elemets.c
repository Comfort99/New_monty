#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pint function is called.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (commands->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
                close_streamlet();
                free_tokens();
                free_commands();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", commands->head->n);
}
