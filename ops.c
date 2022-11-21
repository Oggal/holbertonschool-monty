#include "monty.h"

/**
 * push -
 *@stack
 *@line_num
 */
void push(stack_t **stack, __attribute__ ((unused)) unsigned int line_num)
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
void pall( stack_t **stack,__attribute__ ((unused)) unsigned int line_num)
{
	if (stack == NULL)
		return; /* FAIL */
	if (CURRENT_COMMAND == NULL)
		return; /* FAIL */
	printStack(*stack);
}

/**
 *pint - print top int
 * @stack: Current Stack
 * @line_num: Current Line
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL)
		return;
	if (CURRENT_COMMAND == NULL)
		return;
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%i\n", (*stack)->n);
}
