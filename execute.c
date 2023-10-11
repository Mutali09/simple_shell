#include "shell.h"
/**
 * execute - function to check if full_path, builtin, or single command
 * @cmd: the command to execute (both full_path and a single command)
 *
 * Return: status of the exectution
*/
int execute(const char *cmd)
{
	int status;
	char *full_path, **args = NULL;

	if (is_full_path(cmd))
	{
		full_path = strdup(cmd);
		if (full_path == NULL)
		{
			perror("strdup error");
			free(args);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		if (execute_builtin(cmd) == 0)
		{
			free(args);
			return (0);
		}
		full_path = _which(cmd);

		if (full_path == NULL)
		{
			print_error("Full_path null: Command not found");
			free(args);
			return (EXIT_FAILURE);
		}
	}
	args = (char **)malloc(2 * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc error"), free(full_path);
		return (EXIT_FAILURE);
	}

	args[0] = full_path;
	args[1] = NULL;

	status = execute_command(full_path, args);
	free(full_path), free(args);
	return (status);
}
/**
 * is_full_path - function to check whether the command if full_path
 * @cmd: the command to be checked
 *
 * Return: status of the execution
*/
int is_full_path(const char *cmd)
{
	return (strchr(cmd, '/') != NULL);
}
/**
 * execute_builtin - function to help in the execution of builtin functions
 * @cmd: command to be checked/ executed
 *
 * Return: 1 to indicate builtin command execution or 0 for non_builtin
*/
int execute_builtin(const char *cmd)
{
	int i = 0;
	const builtin_command builtins[] = {
		{"cd", execute_cd},
		{"exit", shell_exit},
		{"env", execute_env},
		{NULL, NULL}
	};

	for (; builtins[i].name != NULL; ++i)
	{
		if (strcmp(cmd, builtins[i].name) == 0)
		{
			builtins[i].function(NULL);
			return (0);
		}
	}
	return (1);
}
/**
 * execute_command - function to execute commands using a child process
 * @full_path: the full path
 * @args: the arguments
 *
 * Return: status of the execution
*/
int execute_command(const char *full_path, char *const args[])
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			print_error("Child process did not terminate normally");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_FAILURE);
}

/**
 * execute_cmds - function to execute an array of commands
 * @tokens: array of commands
 *
 * Return: 0 for success and 1 for failure
*/
int execute_cmds(char **tokens)
{
	int i = 0;
	int status;

	for (; tokens[i] != NULL; i++)
	{
		status = execute(tokens[i]);

		if (status != 0)
		{
			print_error("Command failed");
			return (1);
		}
	}
	return (0);
}

