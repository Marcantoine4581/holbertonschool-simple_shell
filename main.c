#include "shell.h"

char **tokenizer(char* cmd);

/**
 * main - main function
 * Description: main function
 * @argc: number of arguments when executing
 * @argv: pointer to arguments typed when executing
 * Return: 0
 */

int main ()
{
	size_t n;
	char *buffer = NULL;
	char **argv;
	int i;
	char *fullcmd;

	write(1, ":) ", 3);
	getline(&buffer, &n, stdin);
	argv = tokenizer(buffer);
	printf("this is argv[0] : %s\n", argv[0]);
	fullcmd = malloc(sizeof(char) * 20);
	fullcmd = find_path(argv[0]);
/*	for ( i = 0; argv[i]; i++)
	printf("this is %d : %s\n", i, argv[i]);*/
	execve(fullcmd, argv, environ);
	return (0);
}
