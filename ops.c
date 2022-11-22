#include "monty.h"

/**
 * push - Push Item to head
 *@stack: Current Stack
 *@line_num: Current Line
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
void pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_num)
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

/**
 *pop - pop top of the stack
 * @stack: Current Stack
 * @line_num: Current Line
 */
void pop(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL)
		return;
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	popHead(stack);
}

/**
 *swap - swap top 2 stack values
 *@stack: Current Stack
 *@line_num: Line Number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (stack == NULL)
		return;
	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n",
			line_num);
		freeStack(*stack);
		free(CURRENT_COMMAND->opcode);
		free(CURRENT_COMMAND);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
