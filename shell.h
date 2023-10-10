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




/* execute.c */
int execute(const char *cmd);
int is_full_path(const char *cmd);
int execute_command(const char *full_path, char *const args[]);
int execute_cmds(char **tokens);

/* filecheck.c */
int file_exists(const char *path);
int is_executable(const char *path);

/* inhouse.c */
void execute_env(char **argv);
void shell_exit(char **argv);
int change_directory(const char *new_dir);
void execute_cd(char *argv[], int argc);
void update_env_variables(const char *old_dir, const char *new_dir);

/* path.c */
char *_which(const char *cmd);

/* printer.c */
int _putchar(char c);
int print_s(char *str);
void print_error(const char *message);

/* reader.c */
char *read_input(void);
char *remove_comments(const char *str);
char *remove_spaces(const char *str);
char *remove_comments_spaces(const char *str);


/* signal.c */
void get_sig(int sig);
void get_quit(int sig);
int determine_mode(void);

/* string.c */
int _atoi(char *s);

/* strings.c */
char *_strchr(const char *s, int c);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strlen(const char *s);

/* tokenize.c */
char **tokenize_path(const char *path);
char **tokenize_input(char *input);



#endif /* SHELL_H */