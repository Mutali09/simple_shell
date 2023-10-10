#include "shell.h"
/**
 * execute_cmd_in_child - function to execute command using a child process
 * @full_path: - pointer to the complete path
 * @argv: pointer to an array of args
 * @envp: pointer to the environment
 *
 * Return: None
 */
void execute_cmd_in_child(char *full_path, char *argv[], char *envp[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		/* Start of the Child */
		if (argv[1] && argv[1][0] == '"' && argv[1][strlen(argv[1]) - 1] == '"')
		{
			argv[1][strlen(argv[1]) - 1] = '\0';
			argv[1]++;
		}
		if (execve(full_path, argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
			/* Parent Process */

		do {
			waitpid(child_pid, &status, 0);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
