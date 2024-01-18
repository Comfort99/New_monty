#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the push function is called.
 */
void push(stack_t **stack, unsigned int line_number)
{
        stack_t *tmp = commands->head;
	if (commands->n_tokens <= 1 || !(is_number(commands->tokens[1])))
	{
		free_commands();
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();
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
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = *stack;
			(*stack)->prev = tmp;
		}
	}
	commands->stack_length += 1;
}
