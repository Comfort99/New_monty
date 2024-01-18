#include "monty.h"

/**
 * pall - Prints all the elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pall function is called.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (commands->head == NULL)
		return;

	(void) line_number;
	(void) stack;

	temp = commands->head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
