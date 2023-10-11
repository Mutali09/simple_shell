#include "shell.h"
/**
 * read_input - function to read a line of input from the standard input
 *
 * Return: the function returns the read input.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_len;
	int mode = determine_mode();

	input_len = getline(&input, &input_size, stdin);

	if (input_len == -1) /*Handling EOF here*/
	{
		if (mode == INTERACTIVE_MODE)
		{
			write(STDERR_FILENO, "\n", 1);
			free(input);
		}
		exit(0);
	}

	/* Removing the newline char if present*/
	if (input_len > 0 && input[input_len - 1] == '\n')
	{
		input[input_len - 1] = '\0';
	}
	return (input);
}
/**
 * remove_comments - function to remove coments from a str
 * @str: the string
 *
 * Return: a new string without the comments
 */
char *remove_comments(const char *str)
{
	char *result, *comment;

	result = _strdup(str);

	if (!result)
		return (NULL);

	comment = _strchr(result, '#');

	if (comment)
		*comment = '\0';

	return (result);
}

/**
 * remove_spaces - function to remove spaces from a str
 * @str: the string
 *
 * Return: str without leading and trailing spaces
 */
char *remove_spaces(const char *str)
{
	const char *end;
	char *trimmed;
	size_t len;

	while (*str == ' ')
		str++;

	end = str;

	while (*end)
		end++;
	end--;

	while (end >= str && *end == ' ')
		end--;

	len = end - str + 1;

	trimmed = malloc(len + 1);

	if (trimmed)
	{
		strncpy(trimmed, str, len);
		trimmed[len] = '\0';
	}
	return (trimmed);
}
/**
 * remove_comments_spaces - function to remove comments and then spaces
 * @str: the string
 *
 * Return: the new string without comments and spaces
 */
char *remove_comments_spaces(const char *str)
{
	char *without_comments = remove_comments(str);
	char *result;

	if (!without_comments)
		return (NULL);

	result = remove_spaces(without_comments);

	free(without_comments);

	return (result);
}
