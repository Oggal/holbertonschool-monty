#include "monty.h"

/**
 * add - combine top two nodes
 *@stack: Current Stack
 *@line_num: Line Number
 */
void add(stack_t **stack, unsigned int line_num)
{
	int i;
	if (stack == NULL)
		return;
	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	i = popHead(stack);
	(*stack)->n += i;

}
