#include "monty.h"

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: Pointer to the stack.
 * @line_number: Line number where the mul function is called.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *pt1, *pt2;

	(void) stack;
	if (commands->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		/*free_all_args();*/
		exit(EXIT_FAILURE);
	}

	pt1 = commands->head;
	pt2 = pt1->next;

	if (pt1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		/*free_all_args();*/
		exit(EXIT_FAILURE);
	}

	pt2->n = pt2->n % pt1->n;
	delete_stack_node();

	commands->stack_length -= 1;
}
