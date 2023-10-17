#include "shell.h"
/**
 * get_sig - function to get a Ctrl + C signal
 * @sig: signal handler
 *
 * Return: none
 */
void get_sig(int sig)
{
	UNUSED(sig);
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
/**
 * get_quit - function to get a Ctrl + D signal
 * @sig: signal handler
 *
 * Return: none
 */
void get_quit(int sig)
{
	UNUSED(sig);
	exit(0);
}
/**
 * determine_mode - function to determine the mode
 * INTERACTIVE MODE: user passes any cmd line args
 * NON_INTERACTIVE MODE: commands are passed using the pipe
 *
 * Return: 1 - Interactive 0 - non-interactive
 */
int determine_mode(void)
{
	return (isatty(STDIN_FILENO) ? INTERACTIVE_MODE : NON_INTERACTIVE_MODE);
}
