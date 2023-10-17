#include "shell.h"
/**
 * execute - function to check if full_path, builtin, or single command
 * @cmd: the command to execute (both full_path and a single command)
 * @shell_name: the name of the shell
 * Return: status of the exectution
*/
int execute(char **cmd, const char *shell_name)
{
	int status, mode = determine_mode();
	char *full_path = NULL;

	if (is_full_path(cmd[0]))
	{
		if (file_exists(cmd[0]) && is_executable(cmd[0]))
		{
			full_path = _strdup(cmd[0]);
		}
		else
		{
			print_error_message(shell_name, cmd, mode);
			free(full_path), manual_free(cmd);
			return (127);
		}
		if (full_path == NULL)
		{
			perror("strdup error");
			return (127);
		}
	}
	else
	{
		full_path = _which(cmd[0]);

		if (full_path == NULL)
		{
			print_error_message(shell_name, cmd, mode);
			free(full_path), manual_free(cmd);
			return (EXIT_FAILURE);
		}
	}
	status = execute_command(full_path, (char *const*)cmd);
	free(full_path), manual_free(cmd);
	return (status);
}
/**
 * is_full_path - function to check whether the command if full_path
 * @cmd: the command to be checked
 *
 * Return: status of the execution
*/
int is_full_path(char *cmd)
{
	if (cmd == NULL)
	{
		return (0);
	}
	return ((cmd != NULL && cmd[0] == '/') || (cmd[0] == '.'));
}
/**
 * execute_builtin - function to help in the execution of builtin functions
 * @cmd: command to be checked/ executed
 *
 * Return: 1 to indicate builtin command execution or 0 for non_builtin
*/
int execute_builtin(char **cmd)
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
		if (_strcmp(cmd[0], builtins[i].name) == 0)
		{
			builtins[i].function(cmd);
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
		return (127);
	}

	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("execve: ");
			exit(2);
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
			return (127);
		}
	}
	return (127);
}
