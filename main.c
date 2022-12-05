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
	char *buffer, *exit = "exit";
	char **argv2;
	char *fullcmd;
	pid_t pid;
	int keepgoing = 1;	

	while (keepgoing)
	{
		buffer = NULL;
		read = getline(&buffer, &n, stdin);
		if (read == -1)
			break;
		argv2 = tokenizer(buffer);
		if (argv2 == NULL)
			continue;
		if (_strcmp(argv2[0], exit) == 0)
			{
				keepgoing = 0;
				break;
			}
		fullcmd = malloc(sizeof(char) * 20);
		fullcmd = find_path(argv2[0]);
		if (fullcmd != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(fullcmd, argv2, environ);
			}
			else
			{
				wait(NULL);
			}
		}
	}

	return (0);
}
