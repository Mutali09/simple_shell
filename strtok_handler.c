#include "shell.h"

/**
 * custom_tokenize - Tokenize a string based on specified delimiters
 * @str: The string that is to be tokenized
 * @delim: A string that contains the delimiters
 * 
 * Return: The token or NULL if no more tokens.
 */
char *custom_tokenize(char *str, const char *delim)
{
	static char *remainder_str;
	char *curent_token;

	if (str != NULL)
		remainder_str = str;
	if (remainder_str == || *remainder_str == '\0')
		return NULL;
	while (*remainder_str != '\0' && is_in_delimiters(delim, *remainder_str))
		remainder_str++;
	if (*remainder_str == '\0')
		return NULL;
	current_token = remainder_str;
	while (*remainder_str != '\0' && !is_in_delimiters(delim, *remainder_str))
		remainder_str++;
	if (*remainder_str != '\0')
	{
		*remainder_str = '\0';
		remainder_str++;
	}
	return (current_token);
}
