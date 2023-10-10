#include "shell.h"
/**
 * execute_env - function to execute the env command from the stdin
 * @argv: included to match the struct. Not used for this function
 * Return: none
 */
void execute_env(char **argv)
{
	char **env;

	UNUSED(argv);

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
 * @argv: the arguments to be passed
 * Return: none
 */
void shell_exit(char **argv)
{
	/** parsing the args */
	char *command = argv[0];
	char *exit_code = argv[1];
	int exit_status;

	/* is the first argument exit */
	if (_strcmp(command, "exit") != 0)
	{
		return;
	}
	exit_status = 0;

	if (exit_code != NULL)
	{
		exit_status = atoi(exit_code);
	}
	exit(exit_status);
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
 * @argv: the command cd
 *
 * Return: None
 */
void execute_cd(char **argv)
{
	const char *new_dir;
	char *current_dir;

	if (argv[1] == NULL || strcmp(argv[1], "~") == 0)
	{
		new_dir = getenv("HOME");
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		new_dir = getenv("OLDPWD");
	}
	else
	{
		new_dir = argv[1];
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
	free(current_dir);
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
