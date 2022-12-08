#include "shell.h"

/**
 * main - main function
 * Description: main function
 * Return: 0
 */

int main(void)
{
	size_t n = 0;
	ssize_t read = 0;
	char *pexit = "exit";
	int keepgoing = 1;

	while (keepgoing)
	{
		_prompt();
		buffer = NULL;
		read = getline(&buffer, &n, stdin);
		signal(SIGINT, INThandler);
		if (read == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		argv2 = tokenizer(buffer);
		if (argv2 == NULL)
		{
			free(buffer);
			continue;
		}
		if (_strcmp(argv2[0], pexit) == 0)
		{
			freedoublep(argv2);
			free(buffer);
			return (2);
		}
		finalcmd = find_path(argv2[0]);
		if (finalcmd != NULL)
			executecmd();
		else
			freeall();
	}
	return (0);
}
