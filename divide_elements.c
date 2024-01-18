#include "monty.h"

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the _div function is called.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (commands->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		/*free_all_args();*/
		close_streamlet();
		free_tokens();
		free_commands();
                exit(EXIT_FAILURE);
	}

	temp1 = commands->head;
	temp2 = temp1->next;

	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		/*free_all_args();*/
		close_streamlet();
		free_tokens();
		free_commands();
		exit(EXIT_FAILURE);
	}

	temp2->n = temp2->n / temp1->n;
	delete_stack_node();

	commands->stack_length -= 1;
}
