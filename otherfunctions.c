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
 * _prompt- display a prompt.
 * Description: frees a double pointer
 * @p: double pointer to free
 * Return: void
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "", 0);
}

void  INThandler(int sig)
{
	free(buffer);
	signal(sig, SIG_IGN);
	exit(0);
}
