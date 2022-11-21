#include "monty.h"

/**
 *isDelim - Return 1 if char is delim
 *@c: char to test
 * Return: c is a delim
 */
int isDelim(char c)
{
	char *delims = " \t";
	int i = 0;

	while (delims[i])
	{
		if (c == delims[i])
			return (1);
		i++;
	}
	return (0);

}

/**
 * parse_line -
 * @line_txt:
 * @line_num:
 *
 * Return:
 */
command_t *parse_line(char *line_txt, int line_num)
{
	char *opcode;
	int i = 0;
	command_t *outOp;

	if(!line_txt)
		return (NULL);

	while (isDelim(line_txt[i]))
		i++;
	if (line_txt[i] == '\n')
		return (NULL);
	opcode = (line_txt + i);
	outOp = malloc(sizeof(command_t));
	if (!outOp)
		return (NULL);
	outOp->line_num = line_num;
	for (i = 0; !(isDelim(opcode[i]) || opcode[i] == '\n'); i++)
	        ;
	outOp->opcode = strndup(opcode, i);
	outOp->parm_num = atoi(opcode+i);
	return (outOp);
}

/**
 * do_op - Preform correct Operation
 * @stack: pointer to memmory Stack
 * @command: stuct with Command Data
 */
void do_op(stack_t **stack, command_t *command)
{
	/* Meaning of Life */
	instruction_t ops[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{NULL, NULL}
	};
	int i;

	if (stack == NULL)
		return;
	if (command == NULL)
		return;
	if (CURRENT_COMMAND)
	{
		free(CURRENT_COMMAND->opcode);
		free(CURRENT_COMMAND);
	}
	CURRENT_COMMAND = command;
	for( i = 0; ops[i].opcode && strcmp(ops[i].opcode,command->opcode);i++)
		;
	if (ops[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: unknown instructtion %s\n",
			command->line_num, command->opcode);
		exit(EXIT_FAILURE);
	}
	(ops[i].f)(stack, command->line_num);
}
