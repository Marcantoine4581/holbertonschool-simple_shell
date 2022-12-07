#include "shell.h"

/**
 * freedoublep - frees a double pointer
 * Description: frees a double pointer
 * @p: double pointer to free
 * Return: void
 */

void freedoublep(char **p)
{
        int i = 0;

        if (p != NULL)
        {
                for (i; p[i]; i++)
                        free(p[i]);
                free(p);
        }
}
