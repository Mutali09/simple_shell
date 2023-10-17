#include "shell.h"
/**
 * execute_env - function to execute the env command from the stdin
 * @cmd: included to match the struct. Not used for this function
 * Return: none
 */
void execute_env(char **cmd)
{
	char **env;

	manual_free(cmd);

	env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
/**
 * shell_exit - function that exits the shell
 * @cmd: the arguments to be passed
 * Return: none
 */
void shell_exit(char **cmd)
{
	int status;

	if (cmd[1] != NULL)
	{
		status = _atoi(cmd[1]);
	}
	else
	{
		status = 0;
	}
	manual_free(cmd);
	exit(status);
}
/**
 * change_directory - function to change the current directory
 * @new_dir: the new directory
 *
 * Return: 0 for success and 1 for failure
 */
int change_directory(const char *new_dir)
{
	if (chdir(new_dir) == -1)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

/**
 * execute_cd - function to execute the change dir command
 * @cmd: the command cd
 *
 * Return: None
 */
void execute_cd(char **cmd)
{
	const char *new_dir;
	char *current_dir;

	if (cmd[1] == NULL || _strcmp(cmd[1], "~") == 0)
	{
		new_dir = get_env("HOME");
	}
	else if (_strcmp(cmd[1], "-") == 0)
	{
		new_dir = get_env("OLDPWD");
	}
	else
	{
		new_dir = cmd[1];
	}

	current_dir = getcwd(NULL, 0);

	if (current_dir == NULL)
	{
		perror("getcwd");
		return;
	}

	if (change_directory(new_dir))
	{
		update_env_variables(current_dir, new_dir);
	}
	free(current_dir), manual_free(cmd);
}
/**
 * update_env_variables - function to upadate the PWD and OLDPWD env variables
 * @old_dir: the old directory
 * @new_dir: the new directory
 *
 * Return: None
 */
void update_env_variables(const char *old_dir, const char *new_dir)
{
	setenv("OLDPWD", old_dir, 1);
	setenv("PWD", new_dir, 1);
}
