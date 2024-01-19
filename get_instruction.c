#include "monty.h"
/**
 * invalid_instruction - Handles an unknown instruction.
 */
void invalid_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			commands->line_number, commands->tokens[0]);
        close_streamlet();
        free_tokens();
        free_commands();

	exit(EXIT_FAILURE);
}
/**
 * get_instruction - Sets the instruction based on the first token
 * in the input line
 */
void get_instruction(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push}, {"pop", &pop},
		{"pint", &pint}, {"swap", &swap},
		{"nop", &nop}, {"add", &add},
		{"pall", &pall}, {"sub", &sub},
                {"div", &_div}, {"mul", &mul},
                {"mod", &mod},
		{NULL, NULL}
	};

	if (commands->n_tokens == 0)
		return;
	if (commands->tokens[0][0] == '#')
	{
		commands->instruction->opcode = "nop";
		commands->instruction->f = nop;
		return;
	}
	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, commands->tokens[0])
				== 0)
		{
			commands->instruction->opcode = instructions[i].opcode;
			commands->instruction->f = instructions[i].f;
			return;
		}
	}
	invalid_instruction();
}
/**
 * run_instruction - Runs the instruction specified by the commands.
 */
void run_instruction(void)
{
	stack_t *stack = NULL;

	if (commands->n_tokens == 0)
		return;

	commands->instruction->f(&stack, commands->line_number);
}
