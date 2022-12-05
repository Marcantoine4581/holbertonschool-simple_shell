#include "shell.h"

/**
 * _strlen - counts the length of a string
 * Description: counts the length of a string
 * @s: string to count
 * Return: length of str
 */

int _strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}

/**
 * _strcat - appends two strings
 * Description: appends src string to dest string
 * @dest: string to append to
 * @src: string to append from
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 = s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strdup - duplicates a string using malloc
 * Description: duplicates a string
 * @src: string to duplicate
 * Return: pointer to newly created string
 */

char *_strdup(char *src)
{
	char *str;
	char *p;
	int length = 0;

	while (src[length])
		length++;
	str = malloc(length + 1);
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}

/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
