#include "shell.h"
/**
 * tokenize_path - function to be used to tokenize the path
 * @path: the pointer to the path to be tokenized
 *
 * Return: pointer to the array of tokens
*/
char **tokenize_path(const char *path)
{
	char **tokens, *token, *path_copy = NULL;
	const char *ptr;
	int i = 0, count = 0;

	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		return (NULL);
	}

	for (ptr = path_copy; *ptr != '\0'; ++ptr)
	{
		if (*ptr == ':')
		{
			count++;
		}
	}

	tokens = malloc((count + 2) * sizeof(char *));

	if (tokens == NULL)
	{
		perror("malloc error");
		free(path_copy);
		return (NULL);
	}

	token = strtok((char *)path_copy, ":");

	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, ":");
	}
	tokens[i] = NULL;

	free(path_copy);
	return (tokens);
}
/**
 * tokenize_input - split the commnad given by the user
 * @input: provided input by the user
 * Return: a pointer to the tokenized command
 */

char **tokenize_input(char *input)
{
	char **cmd = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;
	char *input_copy = _strdup(input);

	if (input_copy == NULL)
	{
		return (NULL);
	}
	for (i = 0; input_copy[i]; i++)
	{
		if (input_copy[i] == ' ')
			size++;
	}

	cmd = malloc(sizeof(char *) * (size + 2));
	if (cmd == NULL)
	{
		free(input_copy);
		return (NULL);
	}
	token = strtok(input_copy, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		cmd[i] = _strdup(token);
		if (cmd[i] == NULL)
		{
			manual_free(cmd);
			free(input_copy);
			return (NULL);
		}
		token = strtok(NULL, " \n\t\r");
	}
	cmd[i] = NULL;

	free(input_copy);
	return (cmd);
}
