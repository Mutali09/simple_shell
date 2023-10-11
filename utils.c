#include "shell.h"
/**
 * manual_free - function to free the memory
 * @str: the string to be freed
 *
 * Return: none
*/
void manual_free(char **str)
{
	size_t i;

	if (str == NULL || *str == NULL)
	{
		return;
	}
	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	free(str);
}
/**
 * is_builtin - function to check if the command is a builtin
 * @cmd: the command to be checked
 * Return: status of the execution
*/
int is_builtin(const char *cmd)
{
	int i;
	char *builtin_commands[] = {
		"cd", "exit", "env", "set", "unset", "help", NULL
	};
	for (i = 0; builtin_commands[i] != NULL; i++)
	{
		if (strcmp(cmd, builtin_commands[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}