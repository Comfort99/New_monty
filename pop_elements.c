#include "monty.h"

/**
 * pop - Deletes the top element in the present stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the pop function is called.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (commands->head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		/*free_all_args();*/
                close_streamlet();
                free_tokens();
                free_commands();
		exit(EXIT_FAILURE);
	}

	delete_stack_node();
	commands->stack_length -= 1;
}
