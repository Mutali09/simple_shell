#include "shell.h"
/**
 * file_exists - function to check the if a file exists
 * @path: pointer to the path
 *
 * Return: Always zero for success
 */
int file_exists(const char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
	{
		return (1); /* File Exists*/
	}
	return (0); /* Failure */
}

/**
 * is_executable - function to check if a file is executable
 * @path: the pointer to the path of the file
 *
 * Return: 0 - Sucess 1 - Failure
 */
int is_executable(const char *path)
{
	struct stat st;

	if (stat(path, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		return (1);/* is executable */
	}
	return (0); /* is not executable */
}
