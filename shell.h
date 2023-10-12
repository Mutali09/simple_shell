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
/**
 * struct builtin_command - struct to represent the builtin_commands
 * @name: name of the command
 * @function: the function to be applied (pointer)
 */
typedef struct builtin_command
{
	const char *name;
	void (*function)(char **argv);
} builtin_command;




/* execute.c */
int execute(char *const cmd[]);
int is_full_path(const char *cmd);
int execute_command(const char *full_path, char *const args[]);
int execute_builtin(const char *cmd);

/* filecheck.c */
int file_exists(const char *path);
int is_executable(const char *path);

/* inhouse.c */
void execute_env(char **argv);
void shell_exit(char **argv);
int change_directory(const char *new_dir);
void execute_cd(char **argv);
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
int str_cmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, const char *src);
char *str_cpy(char *dest, const char *src, size_t n);

/* strings.c */
char *_strchr(const char *s, int c);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
int _strlen(const char *s);

/* tokenize.c */
char **tokenize_path(const char *path);
char **tokenize_input(char *input);

/* utils.c */

void manual_free(char **str);
int is_builtin(const char *cmd);
char *get_env(const char *name);


#endif /* SHELL_H */
