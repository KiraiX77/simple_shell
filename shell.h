#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

#define MAX_NUM_ARGS 64
#define SHELL_NAME "shell"
#define MAX_PATH_LENGTH 4096
extern char **environ;

/* ========== main.c ========== */
int main(int argc, char *argv[]);
void interactive_shell(void);
void non_interactive_shell(char *command);
void process_input(char **args, char *line, int *status);

/* ========== command_execution.c ========== */
int execute_command(char **args, int command_count);
int execute_external_command(char **args, int command_count);
int search_and_execute_in_path(char **args, char *path_copy,
int command_count);
int cd_command(char **args);

/* ========== error_handling.c ========== */
void print_command_not_found(int count, const char *command_name);
void print_no_permission(int count, const char *command_name);
void print_error_message(int count, const char *command_name,
const char *message);

/* ========== path_resolution.c ========== */
void construct_exec_path(char *exec_path, size_t exec_path_size,
const char *path_token, const char *command);
int token_and_command_length_exceeds_buffer_size(const char *path_token,
const char *command, size_t buffer_size);
char *trim(char *str);
void parse_command_args(const char *command, char **args);

/* ========== environment.c ========== */
char *my_getenv(const char *name);
int starts_with_variable_name(const char *env, const char *name,
size_t name_len);
void print_environment(void);
int set_env_variable(const char *name, const char *value);
int unset_env_variable(const char *name);

/* ========== output.c ========== */
int _putchar(char c);
int my_vfprintf(FILE *stream, const char *format, va_list args);
int my_fprintf(FILE *stream, const char *format, ...);
int _strcmp(const char *s1, const char *s2);

/* ========== string_utilities.c ========== */
char *_strdup(const char *str);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, int n);
char *_strncpy(char *dest, const char *src, int n);
void _strncat(char *dest, const char *src, size_t dest_size);

/* ========== vfprintf_str.c ========== */
int my_vfprintf_char(FILE *stream, char ch);
int my_vfprintf_int(FILE *stream, int num);
int my_vfprintf_str(FILE *stream, const char *str);

/* ========== command_utilisities2.c ========== */
int change_directory(const char *path);
int handle_permission_error(int command_count, const char *command_name);
int execute_cd_command(char **args);
int execute_unsetenv_command(char **args);
int execute_setenv_command(char **args);

#endif /* SHELL_H */
