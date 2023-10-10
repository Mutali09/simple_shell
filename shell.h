#ifndef SHELL_H
#define SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

/* Defintions */
#define BUFFER_SIZE 1024
#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0
#define PROMPT "$ "
#define UNUSED(x) (void)(x)

/* Envrionment Definitions*/
extern char **environ; /* to help us access the env variables */


/* Struct Definitions*/
typedef struct
{
	const char *name;
	void (*function)(char **argv);
}builtin_command;




#endif /* SHELL_H */
