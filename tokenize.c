#include "shell.h"
/**
 * tokenize_path - function to be used to tokenize the path
 * @path: the pointer to the path to be tokenized
 *
 * Return: pointer to the array of tokens
*/
char **tokenize_path(const char *path)
{
	char **tokens, *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 10);
	token = strtok((char *)path, ":");

	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, ":");
	}
	tokens[i] = NULL;

	free(token);

	return (tokens);
}
