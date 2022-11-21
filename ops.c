#include "monty.h"

/**
 * push -
 *@stack
 *@line_num
 */
void push(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL)
		return; /* FAIL */
	if (CURRENT_COMMAND == NULL)
		return; /* FAIL */
        addNodeToStack(stack, CURRENT_COMMAND->parm_num);
}

/**
 * pall - print the stack
 * @stack: Current Stack
 * @line_num: Current Line
 */
void pall( stack_t **stack, unsigned int line_num)
{
	if (stack == NULL)
		return; /* FAIL */
	if (CURRENT_COMMAND == NULL)
		return; /* FAIL */
	printStack(*stack);
}
