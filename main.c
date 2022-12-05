#include "shell.h"

/**
 * main - main function
 * Description: main function
 * Return: 0
 */

int main(void)
{
	size_t n;
	char *buffer = NULL;
	char **argv;
	int i;
	char *fullcmd;

	write(1, ":) ", 3);
	getline(&buffer, &n, stdin);
	argv = tokenizer(buffer);
	fullcmd = malloc(sizeof(char) * 20);
	fullcmd = find_path(argv[0]);
	execve(fullcmd, argv, environ);
	return (0);
}
