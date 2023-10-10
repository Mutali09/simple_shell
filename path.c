#include "shell.h"
/**
 * _which - function that returns the full-path of a command
 * @cmd: the command to search
 *
 * Return: full path
*/
char *_which(const char *cmd)
{
	char *cwd, *full_cwd, **tokens, *full_path;
	int i;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		full_cwd = malloc(strlen(cwd) + strlen(cmd) + 2);

		if (full_cwd == NULL)
		{
			free(cwd);
			return (NULL);
		}
		strcpy(full_cwd, cwd);
		strcat(full_cwd, "/");
		strcat(full_cwd, cmd);
		if (file_exists(full_cwd) && is_executable(full_cwd))
		{
			free(cwd);
			return (full_cwd);
		}
		free(full_cwd);
	}
	tokens = tokenize_path(getenv("PATH"));
	for (i = 0; tokens[i] != NULL; i++)
	{
		full_path = malloc(strlen(tokens[i]) + strlen(cmd) + 2);

		strcpy(full_path, tokens[i]);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		if (file_exists(full_path) && is_executable(full_path))
		{
			free(tokens);
			return (full_path);
		}
		free(full_path);
	}
	free(tokens);
	return (NULL);
}
