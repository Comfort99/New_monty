#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the add function is called.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (commands->stack_length < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		/*free_all_args();*/
                close_stream();
	        free_tokens();
	        free_commands();
		exit(EXIT_FAILURE);
	}

	temp1 = commands->head;
	temp2 = temp1->next;

	temp2->n = temp1->n + temp2->n;
	delete_stack_node();

	commands->stack_length -= 1;
}
