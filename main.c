#include "shell.h"
/**
 * main - this is the main function
 * Return: Always 0 for success
 */
int main(void)
{
	char *user_command, *result;
	char **tokenized;

	/* signal(SIGINT, get_sig); */
	signal(SIGQUIT, get_quit);

	determine_mode();

	while (1)
	{
		if (INTERACTIVE_MODE)
		{
			print_s(PROMPT);
		}
		user_command = read_input();

		result = remove_comments_spaces(user_command);

		tokenized = tokenize_input(result);

		if (tokenized != NULL && tokenized[0] != NULL)
		{
			execute_cmds(tokenized);

			free(tokenized);
		}
		free(user_command);
		free(result);
	}

	return (0);
}
