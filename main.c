#include "shell.h"
/**
 * main - this is the main function
 * Return: Always 0 for success
 */
int main(void)
{
	char *user_command;
	char **tokens;

	signal(SIGINT, get_sig);
	signal(SIGQUIT, get_quit);

	determine_mode();

	while (1)
	{
		print_s(PROMPT);
		user_command = read_input();

		tokens = tokenize_input(user_command);

		if (tokens != NULL && tokens[0] != NULL)
		{
			execute_cmds(tokens);

			free(tokens);
		}
		free(user_command);
	}

	return (0);
}
