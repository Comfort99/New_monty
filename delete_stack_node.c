#include "monty.h"

/**
* delete_stack_node - delete node at the head/top
* Return: void
*/
void delete_stack_node(void)
{
	stack_t *tmp;

	tmp = commands->head;
	commands->head = tmp->next;
	free(tmp);
}
