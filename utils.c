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
		if (_strcmp(cmd, builtin_commands[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * get_env - function to get the value of an environment variable
 * @name: the name of the env variable
 *
 * Return: the value of the env variable
*/
char *get_env(const char *name)
{
	int i = 0;
	char **env;
	char *delimiter;

	for (; environ[i] != NULL; i++)
	{
		env = environ;
		delimiter = _strchr(env[i], '=');
		if (delimiter != NULL)
		{
			if (str_cmp(env[i], name, delimiter - env[i]) == 0)
			{
				return (delimiter + 1);
			}
		}
	}
	return (NULL);
}
