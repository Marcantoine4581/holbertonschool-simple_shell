#include "shell.h"

/**
 * _getenv - returns choosen env variable
 * Description: returns choosen env variable (name)
 * @name: env variable we want to return
 * Return: pointer to content of name variable
 */

char *_getenv(const char *name)
{
	char *token = NULL, *buffer;
	char **env_copy = environ;
	int i = 0;

	while (environ[i])
	{
		i++;
	}

	env_copy = malloc(sizeof(char *) * i + sizeof(char *));
	for (i = 0; environ[i]; i++)
	{
		env_copy[i] = _strdup(environ[i]);
	}
	env_copy[i] = NULL;

	i = 0;
	while (env_copy[i])
	{
		token = strtok(env_copy[i], "=");
		if (_strcmp(name, token) == 0)
			break;
		i++;
	}
	token = strtok(NULL, "=");
	buffer = _strdup(token);
	for (i = 0; env_copy[i]; i++)
	{
		free(env_copy[i]);
	}
	free(env_copy[i]);
	free(env_copy);
	return (buffer);
}

/**
 * find_path - checks if command entered in buffer is an existing
 * command in the shell
 * Description: checks in the PATH variable if the command entered in
 * buffer exists in it
 * @buffer: command to check
 * Return: path to the command in PATH, or NULL if it doesn't exist
 */

char *find_path(char *buffer)
{
	int notfound = 0;
	char *token, *path = NULL, *path_copy = NULL, *token_copy = NULL;
	char *temp = _getenv("PATH");
	struct stat st;

	path_copy = malloc(_strlen(temp) + 1);
	_strcpy(path_copy, temp);
	free(temp);
	token = strtok(path_copy, ":");
	if (stat(buffer, &st) == 0)
	{
		notfound = 1;
		return (buffer);
	}
	while (token)
	{
		token_copy = _strdup(token);
		path = malloc(sizeof(char) * (_strlen(token) + _strlen(buffer) + 1));
		path = token_copy;
		_strcat(path, "/");
		_strcat(path, buffer);
		if (stat(path, &st) == 0)
		{
			notfound = 1;
			free(path_copy);
			return (path);
		}
		token = strtok(NULL, ":");
		free(token_copy);
	}
	if (notfound == 0)
	{
		free(path_copy);
		printf("NOT FOUND\n");
	}
	return (NULL);
}
