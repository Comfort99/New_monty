#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack and queue
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struck instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arg_s - hold variables
 * @Path: File that connects to the path from file
 * @line: string which will be the line of text read from stream
 * @line_number: for tracking current line number
 * @tokens: used to store tokens from line
 * @commands: a valid commands from a line
 * @n_tokens; number of tokens created from line
 * @head: head/top of the stack (doubly linked lists of struct stack_s)
 * @stack_length: tracks the number of nodes in the stack
 * @stack: used to determine whether to use stack/queue data structure
 *
 * Description: hold variables that will be used
 * in different functions of the project as well as variables
 * that will require memory allocation and freeing
 */
typedef struct arg_s
{
        FILE *Path;
        char *line;
	unsigned int line_number;
	char **tokens;
	int n_tokens;
	instruction_t *instruction;
	stack_t *head;
	int stack_length;
	int stack;
} arg_t;

extern arg_t *commands;

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif
