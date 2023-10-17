#include "shell.h"
/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* print_s - prints a string
* @str: string to be printed
*
* Return: number of characters printed
*/
int print_s(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
/**
 * print_error - function that prints a message
 * @message: the output error
 *
 * Return: none
 */
void print_error(const char *message)
{
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
}
/**
 * print_err - function to print a custom message
 * @message: the message to be printed
 *
 * Return: none
*/
void print_err(const char *message)
{
	write(STDERR_FILENO, message, _strlen(message));
}
/**
 * print_error_message - function to print an error message
 * @shell_name: the name of the shell
 * @cmd: the command causing the error
 * @mode: the mode of the shell
 *
 * Return: none
*/
void print_error_message(const char *shell_name, char **cmd, int mode)
{
	if (mode == INTERACTIVE_MODE)
	{
		print_err(shell_name), print_err(": No such file or directory\n");
	}
	else
	{
		print_err(shell_name), print_err(": 1: ");
		print_err(cmd[0]), print_err(": "), print_err("not found\n");
		}
}
