#include "shell.h"

/**
 * main - main function
 * Description: main function
 * Return: 0
 */


int main(void)
{
	size_t n;
	ssize_t read;
	char *exit = "exit", *fullcmd = NULL;
	char **argv2;
	pid_t pid;
	int keepgoing = 1;

	while (keepgoing)
	{
		_prompt();
		buffer = NULL;
		read = getline(&buffer, &n, stdin);
		signal(SIGINT, INThandler);
		printf("read = %ld\n", read);
		if (read == -1)
		{
			free(buffer);
			break;
		}
		argv2 = tokenizer(buffer);
		if (argv2 == NULL)
		{
			free(buffer);
			continue;
		}
		if (_strcmp(argv2[0], exit) == 0)
			{
				freedoublep(argv2);
				free(buffer);
				keepgoing = 0;
				break;
			}
		fullcmd = find_path(argv2[0]);
		if (fullcmd != NULL)
		{
			pid = fork();
			if (pid == 0)
				execve(fullcmd, argv2, environ);
			else
				wait(NULL);
		}
		if (fullcmd != NULL)
		{
			if (_strcmp(buffer, fullcmd) != 0)
				free(fullcmd);
			freedoublep(argv2);
			free(buffer);
		}
		else
		{
			freedoublep(argv2);
			free(fullcmd);
			free(buffer);
		}
	}
	return (0);
}
