#include "shell.h"

/**
 * tokenizer - tokenizes from a char* input
 * Description: takes a char* in input and tokenizes it
 * @cmd: cmd to tokenize
 * Return: returns a double pointer to tokenized version of cmd
 */

char **tokenizer(char *cmd)
{
	unsigned int i = 0;
	char *copy_cmd1;
	char *copy_cmd2;
	char *token;
	char **argv = NULL;
	int argc = 0;

	copy_cmd1 = _strdup(cmd);
	copy_cmd2 = _strdup(cmd);
	token = strtok(copy_cmd1, " \n");
	if (token == NULL)
		return (NULL);

	while (token)
	{
		token = strtok(NULL, " \n");
		argc++;
	}

	argv = malloc(sizeof(char *) * (argc + 1));

	token = strtok(copy_cmd2, " \n");
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;
	free(copy_cmd1);
	return (argv);
}
