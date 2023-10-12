#include "shell.h"
/**
 * _which - function that returns the full-path of a command
 * @cmd: the command to search
 *
 * Return: full path
*/
char *_which(const char *cmd)
{
	char *cwd, *full_cwd, **tokens, *full_path = NULL;
	int i;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		full_cwd = malloc(_strlen(cwd) + 1 + _strlen(cmd) + 2);

		if (full_cwd == NULL)
		{
			free(cwd);
			return (NULL);
		}
		_strcpy(full_cwd, cwd);
		strcat(full_cwd, "/");
		strcat(full_cwd, cmd);
		if (file_exists(full_cwd) && is_executable(full_cwd))
		{
			free(cwd);
			return (full_cwd);
		}
		free(full_cwd), free(cwd);
	}
	tokens = tokenize_path(get_env("PATH"));
	for (i = 0; tokens[i] != NULL; i++)
	{
		full_path = malloc(_strlen(tokens[i]) + 1 + _strlen(cmd) + 2);
		if (full_path == NULL)
		{
			free(tokens);
			return (NULL);
		}
		_strcpy(full_path, tokens[i]);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		if (file_exists(full_path) && is_executable(full_path))
		{
			free(tokens);
			return (full_path);
		}
	}
	free(tokens), free(full_path);
	return (NULL);
}
