#include "shell.h"
/**
 * main - main function
 * Description: main function
 * Return: 0
 */

int main(void)
{
	size_t n;
	char *buffer = NULL, *exit = "exit";
	char **argv;
	char *fullcmd;
	pid_t pid;
	int keepgoing = 1;


	while (keepgoing)
	{
		getline(&buffer, &n, stdin);
		argv = tokenizer(buffer);
		if (argv == NULL)
			continue;
		if (_strcmp(argv[0], exit) == 0)
			{
				keepgoing = 0;
				break;
			}
		fullcmd = malloc(sizeof(char) * 20);
		fullcmd = find_path(argv[0]);
		if (fullcmd != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(fullcmd, argv, environ);
			}
			else
			{
				wait(NULL);
			}
		}
	}

	return (0);
}
