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
