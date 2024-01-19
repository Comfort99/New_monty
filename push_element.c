#include "monty.h"
/**
 * push - Pushes an integer into the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the push function is called.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = commands->head;

	if (commands->n_tokens <= 1 || !(is_number(commands->tokens[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_commands();
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_commands();
		exit(EXIT_FAILURE);
	}
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(commands->tokens[1]);
	if (commands->head == NULL)
		commands->head = *stack;
	else
	{
		if (commands->stack)
		{
			(*stack)->next = commands->head;
			commands->head->prev = *stack;
			commands->head = *stack;
		}
		else
		{

			while (ptr->next)
				ptr = ptr->next;
			ptr->next = *stack;
			(*stack)->prev = ptr;
		}
	}
	commands->stack_length += 1;
}
