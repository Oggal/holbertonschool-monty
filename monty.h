#ifndef MY_MONTY
#define MY_MONTY

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct command_s - Hold command, line number, and param
 * @line_num: Line to command is on
 * @parm_num: Value to pass to command;
 * @opcode: Text Representing command
 */
typedef struct command_s
{
	int line_num;
	int parm_num;
	char *opcode;
} command_t;

/* Parser Functions */
command_t *parse_line(char *line_txt, int line_num);
void do_op(stack_t **stack, command_t *command);
/* Life of Brian*/
extern command_t *CURRENT_COMMAND;
void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);

/* Stack Functions */
stack_t *addNodeToStack(stack_t **stack, const int value);
int popHead(stack_t **stack);
int popTail(stack_t **stack);
int printStack(stack_t *stack);
void freeStack(stack_t *stack);

#endif
