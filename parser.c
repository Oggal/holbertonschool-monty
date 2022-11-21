#include "monty.h"

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

	while (line_txt[i] == ' ')
		i++;
	if (line_txt[i] == '\n')
		return (NULL);
	opcode = (line_txt + i);
	outOp = malloc(sizeof(command_t));
	if (!outOp)
		return (NULL);
	outOp->line_num = line_num;
	for (i = 0; !(opcode[i] == ' ' || opcode[i] == '\n'); i++)
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
	{"push",push},
	{"pall",pall},
	{NULL, NULL}
	};
	int i;

	if (stack == NULL)
		return;
	if (command == NULL)
		return; /* Should we panic here?*/
	CURRENT_COMMAND = command;
	for( i = 0; strcmp(ops[i].opcode,command->opcode);i++)
		;
	if (ops[i].opcode == NULL)
		return; /* DO PANIC HERE, UNKNOWN OPERATION */
	(ops[i].f)(stack, command->line_num);
}
