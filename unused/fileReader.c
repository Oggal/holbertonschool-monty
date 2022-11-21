#include "monty.h"

fileReader_t *CreateReader(int fileDesc)
{
	fileReader_t *newFile;

	newFile = malloc(sizeof(fileReader_t));
	if (!newFile)
		return (NULL);
	write(STDOUT_FILENO, "FILREAD\n",8);
	newFile->fileDesc = fileDesc;
	ReadLines(newFile);
	return(newFile);
}

int ReadLines(fileReader_t *file)
{
	sl_strlist_t *newNode, *tail;
	char *currChar; /* starting point of a line*/
	int charIndex; /* loop index */

	write(STDOUT_FILENO, "READLIN\n",8);
	if (!file)
		return (-1);
	file->len = read(file->fileDesc, file->buff, 1024);
	/* Buff is filled, Len is valid, time to populate the lines.*/
	for(charIndex = 0 ; charIndex < file->len; charIndex++)
	{
		write(STDOUT_FILENO, "forCHAR\n",8);
		if(file->buff[charIndex] == '\n')
		{
			if (currChar == NULL)
				continue;
			write(STDOUT_FILENO, "GETCHAR\n",8);
			file->buff[charIndex] = '\0';
			write(STDOUT_FILENO, "GETCHA2\n",8);
			newNode = malloc(sizeof(sl_strlist_t));
			if (!newNode)
				return (charIndex);
			newNode->lineStr = currChar;
			/*newNode->lineNum = */
			/*newNode->len = */
			tail = file->curLine;
			while(tail && tail->next)
				tail = tail->next;
			if (tail)
				tail->next = newNode;
			else
				file->curLine = newNode;
			currChar = NULL;
		}
		if (file->buff[charIndex] == ' ')
		   continue;
		if (currChar == NULL)
			currChar = ((file->buff) + charIndex);
	}
	write(STDOUT_FILENO, "POSTFOR\n",8);
	return (0);
}

char *PopLine(fileReader_t *file)
{
	char *result;
	sl_strlist_t *node;

	if (!file || !file->curLine)
		return (NULL);
	node = file->curLine;
	if ((!file->curLine->next) && file->len == 1024)
		ReadLines(file);
        file->curLine = file->curLine->next;
	result = node->lineStr;
	free(node);
	return (result);
}
