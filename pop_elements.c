#include "monty.h"

/**
 * pop - Deletes the top element in the present stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pop function is called.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) stack;
	if (commands->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
                close_streamlet();
                free_tokens();
                free_commands();
		exit(EXIT_FAILURE);
	}
	tmp = commands->head;
	commands->head = tmp->next;
	free(tmp);

	commands->stack_length -= 1;
}
