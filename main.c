#include "shell.h"
/**
 * main - this is the main function
 * Return: Always 0 for success
 */
int main(void)
{
	char *input, *result, **cmd;

	signal(SIGINT, get_sig);
	signal(SIGQUIT, get_quit);

	determine_mode();

	while (1)
	{
		if (INTERACTIVE_MODE)
		{
			print_s(PROMPT);
		}
		fflush(stdout);
		input = read_input();

		result = remove_comments_spaces(input);

		cmd = tokenize_input(result);

		if (cmd != NULL && cmd[0] != NULL)
		{
			if (is_builtin(cmd[0]))
			{
				execute_builtin(cmd[0]);
				manual_free(cmd), free(result);
			}
			else
			{
			execute(cmd);
			manual_free(cmd), free(result);
			}
		}
		free(input);
	}

	return (0);
}
