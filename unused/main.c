#include "monty.h"


/**
 *main - Program Entry Point
 *@argC: Count of arguments
 *@argV: Values fo arguments
 *
 *Return: EXIT_SUCCESS
 */
int main(int argC, char **argV)
{
	int fileDesc;
	fileReader_t *file;
	stack_t *MontyStack = NULL;

	if (argC != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: %s file\n",argV[0]);
		return (EXIT_FAILURE);
	}
	fileDesc = open(argV[1], O_RDONLY);
	if (fileDesc < 0)
	{
		dprintf(STDERR_FILENO, "ERROR: Can't open file %s\n", argV[1]);
		return (EXIT_FAILURE);
	}
	write(STDOUT_FILENO, "PRE_FILE_OPEN",3);
	file = CreateReader(fileDesc);
	printf("POST_FILE_OPEN\n\n");
	printf("%s\n", PopLine(file));
	close(file->fileDesc);

}
