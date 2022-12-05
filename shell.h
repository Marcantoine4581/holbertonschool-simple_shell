#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global environemnt */
extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/* String functions */
int _strlen(const char *s);
int _strcmp(const char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *src);
char *_strcpy(char *dest, const char *src);

/* Environment functions */
char *find_path(char *cmd);
char *_getenv(const char *name);
char **tokenizer(char *cmd);

/* Singly list functions */
list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *h);
void free_list(list_t *head);

#endif
