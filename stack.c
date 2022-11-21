#include "monty.h"


/**
 *addNodeToStack - Add a node to head of stack
 *@stack: stack to add node to
 *@value: Value of the node
 *
 * Return: new node or NULL;
 */
stack_t *addNodeToStack(stack_t **stack, const int value)
{
	stack_t *newNode;

	if (stack == NULL)
		return (NULL);
	while (*stack && (*stack)->prev)
		*stack = (*stack)->prev;
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
		return (NULL);
	newNode->prev = NULL;
	newNode->next = *stack;
	newNode->n = value;
	if (*stack != NULL)
		(*stack)->prev = newNode;
	return (*stack = newNode);
}

/**
 *printStack - Print a stack, count the nodes
 *@stack: node in stack to print
 *
 *Return: node count
 */
int printStack(stack_t *stack)
{
	stack_t *cur = stack;
	int count = 0;

	if (cur == NULL)
		return (0);
	while (cur->prev)
		cur = cur->prev;
	while (cur)
	{
		dprintf(STDOUT_FILENO, "%i\n", cur->n);
		count++;
		cur = cur->next;
	}
	return (count);
}

/**
 *freeStack - Free a stack
 * @stack: Node in stack to free
 */
void freeStack(stack_t *stack)
{
	stack_t *cur = stack;

	if (cur == NULL)
		return;
	while (cur->prev)
		cur = cur->prev;
	while (cur)
	{
		free(cur->prev);

		if (!(cur->next))
			free(cur);
		else
			cur = cur->next;
	}
}
