#include "shell.h"

/**
 * freedoublep - frees a double pointer
 * Description: frees a double pointer
 * @p: double pointer to free
 * Return: void
 */

void freedoublep(char **p)
{
	int i;

	if (p != NULL)
	{
		for (i = 0; p[i]; i++)
			free(p[i]);
		free(p);
	}
}

/**
 * _prompt - display a prompt.
 * Description: displays a prompt
 * Return: void
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "", 0);
}

/**
 * INThandler - frees buffer when exiting program with ctrl+c
 * Description: frees buffer when exiting program with ctrl+c
 * @sig: signal to intercept (sigint signal)
 * Return: void
 */

void  INThandler(int sig)
{
	free(buffer);
	signal(sig, SIG_IGN);
	exit(0);
}

/**
 * executecmd - executes a command and frees
 * Description: executes a command and fress
 * Return: void
 */

void executecmd(void)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		execve(finalcmd, argv2, environ);
	else
		wait(NULL);
	if (_strcmp(buffer, finalcmd) != 0)
		free(finalcmd);
	freedoublep(argv2);
	free(buffer);
}

/**
 * freeall - frees heap
 * Description: frees argv2, finalcmd and buffer
 * Return: void
 */

void freeall(void)
{
	freedoublep(argv2);
	free(finalcmd);
	free(buffer);
}
