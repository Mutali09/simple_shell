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
	int i = 0, j = 0;
	char *result;

	result = (char *)malloc(_strlen(str) + 1);

	if (!result)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '#' && (i == 0 || str[i - 1] == ' '))
		{
			/* Skip comments at the beginning of the line or preceded by a space */
			while (str[i] != '\0' && str[i] != '\n')
			{
				i++;
			}
		}
		else
		{
			/* Copy non-comment characters to the result string */
			result[j++] = str[i++];
		}
	}

	result[j] = '\0';

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
		str_cpy(trimmed, str, len);
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
	char *without_spaces;
	char *result;

	if (!without_comments)
		return (NULL);

	without_spaces = remove_spaces(without_comments);
	result = remove_quotes(without_spaces);

	free(without_comments);
	free(without_spaces);

	return (result);
}
/**
 * remove_quotes - function to remove quotes from a string
 * @str: the string
 *
 * Return: the new string without quotes
*/
char *remove_quotes(const char *str)
{
	char *result;
	int i = 0, j = 0;

	result = (char *)malloc(_strlen(str) + 1);

	if (!result)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (str[i] != '\0')
	{
		if (str[i] != '\"')
		{
			result[j++] = str[i];
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}
