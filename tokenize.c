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
	const char *ptr;
	int i = 0, count = 0;

	for (ptr = path; *ptr != '\0'; ++ptr)
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
		return (NULL);
	}

	token = strtok((char *)path, ":");

	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, ":");
	}
	tokens[i] = NULL;

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

	if (input == NULL)
		return (NULL);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(input))
		return (NULL);
	cmd = malloc(sizeof(char *) * (size + 2));
	if (cmd == NULL)
		return (NULL);

	token = strtok(input, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		cmd[i] = token;
		token = strtok(NULL, " \n\t\r");
	}
	cmd[i] = NULL;

	return (cmd);
}
